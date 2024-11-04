#include<bits/stdc++.h>
#define ii pair<int,int>

using namespace std;

const int maxn=107;
const int oo=1e9+7;

int n,m,s,t;
int d[maxn];
int trc[maxn],kq[maxn],res;
vector<ii> a[maxn];

void dij(int s)
{
    for(int i=1; i<=n; i++)
        d[i]=oo;
    priority_queue<ii,vector<ii>,greater<ii> >q;
    q.push({0,s});
    d[s]=0;
    while(q.size())
    {
        int u=q.top().second;
        int du=q.top().first;
        q.pop();

        if(du!=d[u])
            continue;

        for(int i=0; i<a[u].size(); i++)
        {
            int v=a[u][i].second;
            int w=a[u][i].first;
            if(d[v]>d[u]+w)
            {
                d[v]=d[u]+w;
                q.push({d[v],v});
                trc[v]=u;
            }
        }
    }
}
void timkq(int s,int t)
{
    int i=t;
    while(i!=0)
    {
        res++;
        kq[res]=i;
        i=trc[i];
    }
    for(int i=res; i>=1; i--)
        cout<<kq[i]<<" ";
}

int main()
{
    cin>>n>>m>>s>>t;
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back(make_pair(w,v));
       // a[v].push_back(make_pair(w,u));
    }
    dij(s);
    if(d[t]==oo)
        cout<<"-1";
    else
    {
        cout<<d[t]<<" ";
        timkq(s,t);
    }
    return 0;
}

