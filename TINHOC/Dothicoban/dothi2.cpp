#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int m,n,s,t,cx[maxn],trc[maxn];
vector <int> a[maxn],kq;
void BFS(int s)
{
    queue <int> q;
    cx[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<a[u].size(); i++)
        {
            int v=a[u][i];
            if(cx[v])
                {trc[v]=u;cx[v]=0;q.push(v);}
        }
    }
}
int main()
{
    cin>>n>>m>>s>>t;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1;i<=n;i++) cx[i]=1;
    for(int i=1;i<=n;i++)
        if(cx[i]) BFS(i);
    int k=t;
    while(trc[k]!=s)
    {
        kq.push_back(k);
        k=trc[k];
    }
    for(int i=kq.size()-1;i>=0;i--) cout<<kq[i]<<" ";
    return 0;
}
