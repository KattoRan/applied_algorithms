#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+7;
const int oo = 1e8+7;
typedef pair<int,int> ii;

int n,m,s,t;
vector<pair<int, int> > a[N];
int d[N];

int main()
{
	#define name "a"
    ios_base:: sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen(name".inp","r",stdin);
//    freopen(name".out","w",stdout);
	cin >> n >> m;
	while (m--)
	{
		int u,v,w;
		cin >> u >> v >> w;
		a[u].push_back({v,w});
	}
	cin >> s >> t;

	for (int i = 1; i <= n; i++) d[i] = oo;
	priority_queue<ii,vector<ii>,greater<ii> >pq;
    pq.push({0,s});
    d[s] = 0;
    while(pq.size())
    {
    	int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        if(du!=d[u]) continue;

        for (auto i : a[u])
        {
        	int v = i.first;
        	int w = i.second;

        	if(d[u] + w < d[v])
        	{
        		d[v] = d[u] + w;
        		pq.push({d[v],v});
        	}
        }
    }
    cout << d[t] << "\n";
    return 0;
}