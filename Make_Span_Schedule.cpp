#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

int n, m, d[N];
int deg[N];
vector<pair<int,int> > a[N];
vector<int> topo;
int f[N], ans = 0;

void topo_sort()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if(deg[i] == 0) q.push(i);
	while (q.size())
	{
		int x = q.front();
		q.pop();
		topo.push_back(x);
		for (auto i : a[x])
		{
			int y = i.first;
			deg[y]--;
			if (deg[y] == 0) q.push(y);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen("a.inp","r",stdin);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> d[i];
	while (m--)
	{
		int u,v;
		cin >> u >> v;
		a[u].push_back({v,d[u]});
		deg[v]++;
	}
	topo_sort();
	memset(f,0,sizeof f);
	for (int i : topo)
	{
		ans = max(f[i] + d[i], ans);
		for (auto j : a[i])
		{
			int v = j.first;
			int w = j.second;
			f[v] = max(f[v],f[i] + w);
		}
	}
	cout << ans << '\n';
	return 0;
}
