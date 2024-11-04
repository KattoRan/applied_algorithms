#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define task "path"
#define fi first
#define se second
#define ii pair<int,int>
using namespace std;
const int oo=1e9+7;
const int N=1e4+7;
vector<ii> a[N];
typedef long long ll;
int n,m;
ll d[N],f[N];

void dist()
{
    fu(i,1,n) d[i]=oo,f[i]=0;
    priority_queue<ii,vector<ii>,greater<ii> >q;
    q.push({0,1});
    d[1]=0;
    f[1]=1;
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
            if(d[v]==d[u]+w)
                f[v]=f[v]+f[u];
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push({d[v],v});
                f[v]=f[u];
            }
        }
    }
}
void nhap()
{
    cin>>n>>m;
    fu(i,1,m)
    {
        int k,u,v,l;
        cin>>k>>u>>v>>l;
        if(k==1) a[u].push_back({l,v});
        if(k==2) {
            a[u].push_back({l,v});
            a[v].push_back({l,u});
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    nhap();
    dist();
    cout<<d[n]<<" "<<f[n];
}
