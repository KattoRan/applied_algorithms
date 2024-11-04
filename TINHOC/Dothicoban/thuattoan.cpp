#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int m,n,cx[maxn];
vector <int> a[maxn];
void BFS(int s)
{
    queue <int> q;
    cx[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        // cout<<u<<" ";
        q.pop();
        for(int i=0;i<a[u].size();i++)
        {
            int v=a[u][i];
            if(cx[v]) cx[v]=0,q.push(v);
        }
    }
}
void DFS(int s)
{
    cx[s]=0;
    //cout<<s<<" ";
     for(int i=0;i<a[s].size();i++)
        {
            int v=a[s][i];
            if(cx[v]) trc[v]=u,DFS(v);
        }
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cx[i]=1;
    //demlt=0;
    for(int i=1;i<=n;i++)
        if(cx[i]) DFS(i);//BFS(i);{demlt++;}
    return 0;
}

