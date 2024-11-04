#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define name "count"
using namespace std;
const int maxn=1e6+3;
const int oo=1e9+1;
typedef long long ll;
typedef pair<ll,ll>ii;
int n,res,cx[maxn];
ii a[maxn],b[maxn];
ll dem;
void read(ll &x)
{
    x=0;
    int tam=1;
    char c=getchar();
    if((c<'0'||c>'9')&&c!='-') exit(0);
    if(c=='-')
    {
        tam=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}
void sang()
{
    cx[0]=1;
    cx[1]=1;
    fu(i,2,sqrt(maxn))
    {
        int j=i*i;
        while(j<=maxn)
        {
            cx[j]=1;
            j+=i;
        }
    }
}
void enter()
{
    cin>>n;
    fu(i,1,n)
    {
        read(a[i].fi);
        read(a[i].se);
        read(b[i].fi);
        read(b[i].se);
    }
    sang();
}
void solve()
{
    fu(i,1,n)
    {
        dem=sqrt((a[i].fi-b[i].fi)*(a[i].fi-b[i].fi)+(a[i].se-b[i].se)*(a[i].se-b[i].se));
        if(cx[dem]==0) res++;
    }
    cout<<res;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    #endif // ONLINE_JUDGE
    enter();
    solve();
    cerr<<"\ntime: "<<clock()*1000/CLOCKS_PER_SEC<<"ms";
}
