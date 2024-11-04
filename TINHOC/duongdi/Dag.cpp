#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
const int maxm=1e5+7;
const int oo=1e9+7;
int nv[maxn],n,m,deg[maxn],num;
vector <int> a[maxn];
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
           int v=a[u][i];
           deg[v]--;
           if(deg[v]==0) q.push(v);
       }
   }
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
    numbering();
    for(int i=1; i<=n; i++)
        cout<<nv[i]<<'\n';
    return 0;
}
