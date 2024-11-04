#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define catlan main
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e6+7;
long long n;
int a[N],dem,last;
ii b[N];
template <typename T> void read(T&x)
{
    int tam=1;
    char c=getchar();
    x=0;
    while(!isdigit(c)&&c!='-')
        c=getchar();
    if(c=='-')
        tam=-1,c=getchar();
    while(isdigit(c))
    {
        x=x*10+c-48;
        c=getchar();
    }
    x*=tam;
}
bool cmp(ii a,ii b)
{
    if(a.fi==b.fi) return a.se<b.se;
    return a.fi<b.fi;
}
catlan()
{
    #define name "ziparr"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    fu(i,1,n) read(a[i]),b[i]={a[i],i};
    sort(b+1,b+n+1,cmp);
    dem=0;
    last=b[n].fi;
    fu(i,1,n)
    {
        if(b[i].fi!=last) dem++,last=b[i].fi;
        a[b[i].se]=dem;
    }
    fu(i,1,n) cout<<a[i]<<" ";

}
