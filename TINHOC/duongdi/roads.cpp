#include<bits/stdc++.h>
#define ii pair<int,int>

using namespace std;

const int maxn=100;
const int oo=1e9+8;

int n,m,k,res,st;
bool cxn[maxn];
int d[maxn],dn[maxn];
int c[maxn],cn[maxn];
vector< pair<int,pair<int,int> > >a[maxn],b[maxn];

void dij1()
{
    for(int i=1;i<=n;i++) d[i]=oo,c[i]=0;
    priority_queue<ii,vector<ii>,greater<ii> >q;
    d[1]=0;
    q.push({0,1});
    while(q.size()){
        int u=q.top().second;
        int du=q.top().first;
        q.pop();

        if(du!=d[u]) continue;

        for(int i=0;i<a[u].size();i++){
            int v=a[u][i].first;
            int w=a[u][i].second.first;
            int gia=a[u][i].second.second;
            if(d[v]>d[u]+w&&c[v]+gia<=k){
                d[v]=d[u]+w;
                q.push({d[v],v});
                c[v]=c[u]+gia;
            }
        }
    }
}

void dijn(int s)
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
            int w=b[u][i].second.first;
            int gia=b[u][i].second.second;
            if(cxn[v]&&dn[u]+w<dn[v]&&cn[u]+gia<=k) dn[v]=dn[u]+w,cn[v]=cn[u]+gia;
        }
    }
}

int main()
{
    cin>>st;
    while(st>0)
    {
    cin>>k>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w,c;
        cin>>u>>v>>w>>c;
        a[u].push_back(make_pair(v,make_pair(w,c)));
        b[v].push_back(make_pair(u,make_pair(w,c)));
    }
    dij1();
    dijn(n);
    res=oo;
    for(int i=1;i<=n;i++)
    {
        if(c[i]+cn[i]<=k) res=min(res,d[i]+dn[i]);
    }
    if(res==oo) cout<<"-1";
    else cout<<res;
    st--;
    }
}
