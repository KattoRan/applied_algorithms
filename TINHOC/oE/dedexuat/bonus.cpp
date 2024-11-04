#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
const int oo=1e9+7;
int n,m,a[N],b[N];
int mia,mxa,mib,mxb;
long long res;
template<typename T> inline void read(T& x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-')
        c=getchar();
    if(c=='-') tam=-1,c=getchar();
    while(isdigit(c))
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}
main()
{
    #define name "bonus"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    read(m);
    mxa=-oo;
    mxb=-oo;
    mia=oo;
    mib=oo;
    for(int i=1;i<=n;i++)
    {
        read(a[i]);
        mxa=max(mxa,a[i]);
        mia=min(mia,a[i]);
    }
    for(int i=1;i<=m;i++)
    {
        read(b[i]);
        mxb=max(mxb,b[i]);
        mib=min(mib,b[i]);
    }
    res=max(mxa*mxb,mxa*mib);
    res=max(res,(long long)mib*mia);
    res=max(res,(long long)mia*mxb);
    cout<<res;
}
