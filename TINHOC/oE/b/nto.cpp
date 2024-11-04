#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e6+7;
long long t,f[N];
template<typename T> inline void read(T& x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c=='-')
        c=getchar();
    if(c=='-')
    {
        tam=-1;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}
void sang()
{
    f[0]=1;
    f[1]=1;
    for(int i=2;i*i<=1000000;i++)
        if(f[i]==0)
        for(int j=i*i;j<=1000000;j+=i)
        if(f[j]==0) f[j]=1;
    int d=0;
    for(int i=2;i<=1000000;i++)
        if(f[i]==0)
    {
        d++;
        f[d]=i;
    }
}
long long k,k1,m[N],p[N],res;
void phantich(long long x)
{
    int i=1,d1;
    k=0;k1=0;
    while(f[i]*f[i]<=x)
    {
        d1=0;
        while(x%f[i]==0){d1++;x/=f[i];k1++;p[k1]=f[i];}
        if(d1>0) {k++,m[k]=d1;}
        i++;
    }
    if(x>1) {k++,m[k]=1;k1++;p[k1]=x;}
}
main()
{
    #define name "nto"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name"inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>t;
    sang();
    while(t--)
    {
        int n;
        cin>>n;
        phantich(n);
        res=1;
        for(int i=1;i<=k;i++)
            res*=(m[i]+1);
        cout<<res<<" ";
        for(int i=1;i<k1;i++)
            cout<<p[i]<<"*";
        cout<<p[k1]<<'\n';
    }
}
