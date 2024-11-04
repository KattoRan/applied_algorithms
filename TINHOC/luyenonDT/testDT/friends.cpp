#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define task "friends"
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;
const int N=1e6+1;
const int oo=1e9+7;
typedef long long ll;
int n,q,res;
int d[N];
vector<ii> a[N];
int dk[N],cxk[N];
void dij()
{
    fu(i,1,n) d[i]=oo;
    priority_queue<ii,vector<ii>,greater<ii> >q;
    q.push({0,1});
    d[1]=0;
    while(q.size())
    {
        int u=q.top().se;
        int du=q.top().fi;
        q.pop();

        if(du!=d[u]) continue;

        for(int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].se;
            int w=a[u][i].fi;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
}
void dijk(int s)
{
    for(int i=0; i<=n; i++)dk[i]=oo,cxk[i]=true;
    dk[s]=0;
    int u;
    while(true)
    {
        u=0;
        for(int v=1; v<=n; v++)
            if(cxk[v]&&dk[v]<dk[u]) u=v;
        if(u==0) break;
        cxk[u]=false;
        for(int i=0; i<a[u].size(); i++)
        {
            int v=a[u][i].se;
            int w=a[u][i].fi;
            if(cxk[v]&&dk[u]+w<dk[v]) dk[v]=dk[u]+w;
        }
    }
}
void nhap()
{
    cin>>n;
    fu(i,1,n-1)
    {
        int u,c;
        cin>>u>>c;
        a[u].push_back({c,i+1});
        a[i+1].push_back({c,u});
    }
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    nhap();
    dij();
    cin>>q;
    while(q--)
    {
        res=0;
        int u,v,t;
        cin>>u>>v>>t;
        a[u].push_back({t,v});
        a[v].push_back({t,u});
        res+=d[u];
        dijk(u);
        res+=dk[v];
        cout<<res<<'\n';
        a[u].pop_back();
        a[v].pop_back();
    }
}
