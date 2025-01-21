//C++ 
#include <bits/stdc++.h> 
using namespace std;
const int N = 1e6+7;
int n;
int res = 0;
int cx[N];
vector<pair<int,int> > a[N];
int d[N];
void dfs(int u)
{
    cx[u] = 1;
    for (auto i : a[u])
    {
        int v = i.first;
        int w = i.second;
        
        if(!cx[v])
            {
                d[v] = d[u] + w;
                dfs(v);
            }
    }
}

int main() 
{ 
    #define name "a"
    ios_base:: sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen(name".inp","r",stdin);
//    freopen(name".out","w",stdout);
    cin >> n;
    int u,v,w;
    while (cin >> u >> v >> w)
    {
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    dfs(1);
    int s = 1;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] > d[s])
            s = i;
    }
    memset(d, 0, sizeof d);
    memset(cx, 0, sizeof cx);
    dfs(s);
    for (int i = 1; i <= n; i++)
        res = max(res,d[i]);
    cout << res << "\n";
    
    return 0;
}