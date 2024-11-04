#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second

using namespace std;
typedef pair<int,int>ii;
typedef long long ll;
const int maxn=1e4+3;
const int oo=1e9+1;

void read(int &x)
{
    x=0;
    char c=getchar();
    int ok=1;
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-') {ok=-1;
    c=getchar();}
    while(c>='0'&&c<='9')
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=ok;
}
int n,a[maxn],f[maxn];
int b[maxn];
int sum;
set<int>se;
bool cmp(int a,int b)
{
    return (a>b);
}
void enter()
{
    read(n);
    fu(i,1,n)
    read(a[i]),sum+=a[i];
    sort(a+1,a+n+1,cmp);
    se.insert(sum);
}
void solve()
{
    fu(i,1,n)
    {
        auto dm=se.lower_bound(2*a[i]);
        if((*dm)<2*a[i]) continue;
        f[i]=(*dm)-2*a[i];
        se.insert(f[i]);
    }
    int best=(sum-(*se.begin()))/2;
    cout<<(ll)(1ll*best*(sum-best));
}
main()
{
    #define name "expression"
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
