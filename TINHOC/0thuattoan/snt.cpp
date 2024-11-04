#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int f[N],m[N];
void sang()
{
    f[0]=f[1]=1;
    for(int i=2;i*i<=1000007;i++)
        if(f[i]==0)
        for(int j=i*i;j<=1000007;j+=i)
        f[j]=1;
    int k=0;
    for(int i=2;i<=1000007;i++)
        if(f[i]==0)
    {
        k++;
        f[k]=i;
    }
}
void ptnt(long long x)
{
    int i=1;
    while(f[i]*f[i]<=x)
    {
        while(x%f[i]==0)
        {
            m[f[i]]++;
            x/=f[i];
        }
        i++;
    }
    if(x>1) m[x]++;
}

void rrh(int a[])
{
    int last=*max_element(a+1,a+n+1);
    sort(b);
    fu(i,1,n)
    {
        if(b[i].x!=last) d++,last=b[i];
        a[b[i].vt]=d;
    }
    // a[i] la so lon thu may trong day ban dau
}
