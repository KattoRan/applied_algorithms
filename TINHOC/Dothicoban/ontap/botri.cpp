#include<bits/stdc++.h>
#define task "botri"
using namespace std;
const int maxn=1e3+7;
int m,n,cx[maxn],demlt,dd[maxn];
vector <int> a[maxn];
void BFS(int s)
{
    queue <int> q;
    cx[s]=0;
    q.push(s);
    dd[s]=demlt;
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
                dd[v]=demlt;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;

    int u,v;
    while(cin>>u>>v)
    {
        a[u].push_back(v);
        a[v].push_back(u);
    }
    for(int i=1; i<=n; i++)
        cx[i]=1;
    demlt=0;
    for(int i=1; i<=n; i++)
        if(cx[i])
        {
            demlt++;
            BFS(i);
        }
    cout<<demlt<<'\n';
    for(int i=1; i<=demlt; i++)
    {
        for(int j=1; j<=n; j++)
            if(dd[j]==i)
                cout<<j<<" ";
        cout<<'\n';
    }
    return 0;
}
