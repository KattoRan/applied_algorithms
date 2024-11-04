#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e6+7;
long long a[N],n;
long long leftmin[N],rightmin[N],leftmax[N],rightmax[N];
long long f[N],g[N];
stack <long long> s,s1,s2,s3;
long long res;
void read(long long &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-')
    {
        c=getchar();
        tam=-1;
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}
int main()
{
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    leftmin[1]=0;
    fu(i,1,n)
    {
        while(!s.empty()&&a[s.top()]>a[i]) s.pop();
        if(s.empty()) leftmin[i]=0;
        else leftmin[i]=s.top();
        s.push(i);
    }
    rightmin[n]=n+1;
    fd(i,n,1)
    {
        while(!s1.empty()&&a[s1.top()]>=a[i]) s1.pop();
        if(s1.empty()) rightmin[i]=n+1;
        else rightmin[i]=s1.top();
        s1.push(i);
    }
    fu(i,1,n)
    if(i>leftmin[i]&&i<rightmin[i])
        f[i] = (i - leftmin[i]) * (rightmin[i] - i);
    leftmax[1]=0;
    fu(i,1,n)
    {
        while(!s2.empty()&&a[s2.top()]<=a[i]) s2.pop();
        if(s2.empty()) leftmax[i]=0;
        else leftmax[i]=s2.top();
        s2.push(i);
    }
    rightmax[n]=n+1;
    fd(i,n,1)
    {
        while(!s3.empty()&&a[s3.top()]<a[i]) s3.pop();
        if(s3.empty()) rightmax[i]=n+1;
        else rightmax[i]=s3.top();
        s3.push(i);
    }
    fu(i,1,n)
    if(i>leftmax[i]&&i<rightmax[i])
        g[i] = (i - leftmax[i]) * (rightmax[i] - i);
    res=0;
    for(int i=1;i<=n;i++)
        res += a[i]*(g[i]-f[i]);
    cout<<res;
}
