#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,a[N],k,tong,d;
long long s[N],s1[N];
bool cmp(int a,int b)
{
    return a>b;
}
void read(int &x)
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
void sub1()
{
    for(int i=1;i<=n; i++)
        for(int j=i; j<=n; j++)
            if(abs(s[j]-s[i-1])>k)
                d++;
    cout<<d;
}
void sub2()
{

    if(s[1]>k||s[1]<-k) d++;
    for(int i=1;i<=n;i++)
    {
        d+=2;
        int cs1=upper_bound(s+1,s+i+1,k-s[i])-s;
        int cs2=upper_bound(s+1,s+i+1,k+s[i])-s;
        if(cs1==i+1) d--;
        if(cs2==i+1) d--;
    }
    cout<<d;
}
main()
{
    #define name "asum"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    read(k);
    for(int i=1; i<=n; i++)
        read(a[i]);
    for(int i=1; i<=n; i++)
        s[i]=s[i-1]+a[i];
    if(n<=10000) sub1();
    else sub2();
}
