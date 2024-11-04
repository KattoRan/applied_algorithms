// cat \\

#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
int n,m;
typedef pair<long long,long long> ii;
#define fi first
#define se second
ii d[N];
long long s1[N],s2[N],res;
bool cmp(long long a,ii b)
{
    return a<b.fi;
}
template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-')
    {
        c=getchar();
        tam=-1;
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
    #define name "talent"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    read(m);
    fu(i,1,n) read(d[i].fi);
    fu(i,1,n) read(d[i].se);
    fu(i,1,n)
    {
        s1[i]=s1[i-1]+d[i].fi*d[i].se;
        s2[i]=s2[i-1]+d[i].se;
    }
    fu(i,1,n)
    fu(i,1,m)
    {
        int p;
        read(p);
        int j=upper_bound(d+1,d+n+1,p,cmp)-d;
        res=0;
        long long t1,t2;
        t1=s1[n]-s1[j-1];
        t2=(s2[n]-s2[j-1])*p;
        res+=t1-t2;
        t1=s1[j-1];
        t2=s2[j-1]*p;
        res+=t2-t1;
        cout<<res<<'\n';
    }
}
