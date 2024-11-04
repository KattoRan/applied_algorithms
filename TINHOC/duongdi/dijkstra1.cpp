#include<bits/stdc++.h>
#define ii pair<int,int>

using namespace std;

const int maxn=107;
const int oo=1e9+7;

int n,m,k;
int d[maxn];
int trc[maxn],kq[maxn],res;
vector<ii> a[maxn];

void dij_heap(int s)
{
    for(int i=1;i<=n;i++) d[i]=oo;
    priority_queue<ii,vector<ii>,greater<ii> >q;
    q.push({0,s});
    d[s]=0;
    while(q.size())
    {
        int u=q.top().second;
        int du=q.top().first;
        q.pop();

        if(du!=d[u]) continue;

        for(int i=0;i<a[u].size();i++)
        {
            int v=a[u][i].second;
            int w=a[u][i].first;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push({d[v],v});
                trc[v]=u;
            }
        }
    }
}
int main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back(make_pair(w,v));
        a[v].push_back(make_pair(w,u));
    }
    for(int i=1;i<=k;i++)
    {
        int x,u,v;
        cin>>x>>u>>v;
        dij_heap(u);
        if(x==0) cout<<d[v]<<'\n';
        if(x==1)
        {
            int i=v;
            while(i!=0)
           {
            res++;
            kq[res]=i;
            i=trc[i];
           }
           cout<<res<<" ";
           for(int i=res; i>=1; i--)cout<<kq[i]<<" ";
           cout<<'\n';
        }
    }
    return 0;
}
