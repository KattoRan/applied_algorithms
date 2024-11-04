#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
const int maxm=1e5+7;
const int oo=1e9+7;
int nv[maxn],n,m,deg[maxn],num;
int trc[maxn];
long long d[maxn];
typedef pair<int,int> ii;
vector <ii> a[maxn];
void numbering(){
   queue<int> q;
   int num;
   for(int i=1;i<=n;i++)
    if(deg[i]==0) q.push(i);
   num=0;
   while(!q.empty())
   {
       int u=q.front();q.pop();
       num++;
       nv[num]=u;
       for(int i=0;i<a[u].size();i++)
       {
           int v=a[u][i].first;
           deg[v]--;
           if(deg[v]==0) q.push(v);
       }
   }
}
void gritical()
{
    d[nv[1]]=0;
    int u=nv[1];
    for(int i=0;i<a[u].size();i++)
    {
        int v=a[u][i].first;
        int w=a[u][i].second;
        d[v]=d[u]+w;
        trc[v]=u;
    }
    for(int i=2;i<=n;i++)
    {
        int u=nv[i];
        for(int j=0;j<a[u].size();j++)
        {
            int v=a[u][j].first;
            int w=a[u][j].second;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                trc[v]=u;
            }
        }
    }
}
void nhap()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back({v,w});
    }
}
int main()
{
    nhap();
    for(int i=1; i<=n; i++)
        deg[i]=0;
    for(int u=1; u<=n; u++)
        for(int i=0; i<a[u].size(); i++)
        {
            int v=a[u][i].first;
            deg[v]++;
        }
    numbering();
    gritical();
    cout<<d[nv[n]];
    return 0;
}

