#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
using namespace std;
const int N=3*1e6+7;
int n,m,a[N],b[N];
long long res;
map<long long,long long> ma,mb;
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
main()
{
    #define name "thuong"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name"inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    read(m);
    fu(i,1,n) read(a[i]);
    fu(i,1,m) read(b[i]);
    fu(i,1,m) mb[b[i]]++;
    fu(i,1,n)
    if(mb[a[i]]==0)
    {
        cout<<a[i]<<" ";
        ma[a[i]]++;
    }
    res=0;
    for(auto i:ma)
    {
        res=max(res,i.fi*i.se);
    }
    if(res!=0) cout<<'\n'<<res;
    else cout<<res;
}
