#include<bits/stdc++.h>
#define task "ltmax"
using namespace std;
const int maxn=1e3+7;
int m,n,cx[maxn],dem;
vector <int> a[maxn];
void BFS(int s)
{
    queue <int> q;
    cx[s]=0;
    q.push(s);
    dem=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int i=0; i<a[u].size(); i++)
        {
            int v=a[u][i];
            if(cx[v])
            {
                cx[v]=0,q.push(v);
                dem++;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int u,v;
        cin>>u>>v;
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
        cx[i]=1;
    int res=0;
    for(int i=1; i<=n; i++)
        if(cx[i])
        {
            BFS(i);
            res=max(res,dem);
        }
    cout<<res;
    return 0;
}
