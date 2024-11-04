// Cat \\
||*---*||
#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define catlan main
#define pb push_back
using namespace std;

const int N=1e3+7;

typedef long long ll;
typedef pair<int,int> ii;
#define vii vector<ii>

vector<int> a[N];
vii b;
int f[N],low[N],num[N];
int n,m;

template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-')
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
void dfs(int u, int p)
{
    f[u]=1;
    low[u]=num[u]=num[0]++;
    for(auto v: a[u])
    {
        if(v==p)
            continue;
        if(num[v])
            low[u]=min(low[u],num[v]);
        else
        {
            dfs(v,u);
            low[u]=min(low[u],low[v]);
            f[u]+=f[v];
            if(low[v]>=num[v])
                b.pb(ii(u,v));
        }
    }
}

void ent()
{
    cin>>n>>m;
    for (int i = 1; i <= m; i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
}

void solve()
{
    dfs(1,0);
    ll res=0;
    for(ii v: b)
        res+= f[v.se]*(n-f[v.se]);
    cout<<res;
}

catlan()
{
#define name "weather"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    ent();
    solve();
}
