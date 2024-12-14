//C++ 
#include <bits/stdc++.h> 
using namespace std;
const int N = 1e6+7;
int n;
int res = 0;
int cx[N];
vector<pair<int,int> > a[N];
int Dfs(int u, int res)
{
    cx[u] = 1;
    int max_res = res;
    for (auto s : a[u])
    {
        int v = s.first;
        int w = s.second;
        if (cx[v] == 0)
        max_res = max(max_res,Dfs(v,res+w));
    }
    cx[u] = 0;
    return max_res;
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
    for (int i = 1; i <= n; i++)
    {
        int s = Dfs(i,0);
        //cout << s << endl;
        res = max(res,s);
    }
    cout << res << endl;
    return 0;
}