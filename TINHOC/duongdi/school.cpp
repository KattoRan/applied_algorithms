#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
const int maxm=1e5+1;
const int oo=1e9+7;
int n,m,k,res,res2;
int d1[maxn],dn[maxn],dk[maxn];
bool cx1[maxn],cxn[maxn],cxk[maxn];
typedef pair<int,int> ii;
vector<ii> a[maxn],b[maxn],c[maxn];
void nhap()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("school.inp","r",stdin);
    freopen("school.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1; i<=m; i++)
    {
        int u,v,x,y;
        cin>>u>>v>>x>>y;
        a[u].push_back({v,y});
        b[v].push_back({u,y});
        c[v].push_back({u,x});
    }
}
void Dijkstra1(int s)
{
    for(int i=0; i<=n; i++)d1[i]=oo,cx1[i]=true;
    d1[s]=0;
    int u;
    while(true)
    {
        u=0;
        for(int v=1; v<=n; v++)
            if(cx1[v]&&d1[v]<d1[u]) u=v;
        if(u==0) break;
        cx1[u]=false;
        for(int i=0; i<a[u].size(); i++)
        {
            int v=a[u][i].first;
            int w=a[u][i].second;
            if(cx1[v]&&d1[u]+w<d1[v]) d1[v]=d1[u]+w;
        }
    }
}
void Dijkstran(int s)
{
    for(int i=0; i<=n; i++)dn[i]=oo,cxn[i]=true;
    dn[s]=0;
    int u;
    while(true)
    {
        u=0;
        for(int v=1; v<=n; v++)
            if(cxn[v]&&dn[v]<dn[u]) u=v;
        if(u==0) break;
        cxn[u]=false;
        for(int i=0; i<b[u].size(); i++)
        {
            int v=b[u][i].first;
            int w=b[u][i].second;
            if(cxn[v]&&dn[u]+w<dn[v]) dn[v]=dn[u]+w;
        }
    }
}
void Dijkstrak(int s)
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
        for(int i=0; i<c[u].size(); i++)
        {
            int v=c[u][i].first;
            int w=c[u][i].second;
            if(cxk[v]&&dk[u]+w<dk[v]) dk[v]=dk[u]+w;
        }
    }
}
int main()
{
    nhap();
    Dijkstrak(k);
    Dijkstra1(1);
    Dijkstran(n);
    if(dk[1]<60) cout<<d1[n]<<" ";
    else
    {res=oo;
    for(int i=1;i<=n;i++)
    {
        int kq=d1[i];
        if(dk[i]+kq<60) res=min(res,dn[i]+kq);
    }
    cout<<res;}
    return 0;
}

