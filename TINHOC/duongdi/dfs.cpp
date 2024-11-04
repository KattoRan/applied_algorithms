#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
const int maxm=1e5+7;
const int oo=1e9+7;
int nv[maxn],n,m,deg[maxn],num,kt[maxn];
bool cx[maxn];
vector <int> a[maxn];
void DFS(int u)
{
    cx[u]=true;
    for(int i=0; i<a[u].size(); i++)
    {
        int v=a[u][i];
        if(cx[v]&&!kt[v]) exit(0);
        if(!cx[v]) DFS(v);
    }
    num++;
    nv[num]=u;
    kt[u]=1;
}
void nhap()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
    }
    for(int i=1; i<=n; i++)
        kt[i]=0,cx[i]=false;
}
int main()
{
    nhap();
    for(int i=1; i<=n; i++)
        deg[i]=0;
    for(int u=1; u<=n; u++)
        for(int i=0; i<a[u].size(); i++)
        {
            int v=a[u][i];
            deg[v]++;
        }
    for(int i=1; i<=n; i++)
        if(deg[i]==0) DFS(i);
    for(int i=1; i<=n; i++)
        cout<<nv[i]<<'\n';
    return 0;
}

