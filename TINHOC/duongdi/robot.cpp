#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define fi first
#define se second
#define N 500
#define INF 1000000000
#define TR(v,it) for(int it=0;it<(v).size();it++)

int gas[N], c[N][N], n, m,d[N];
vii g[N];
vi t[N];

void nhap() {
    freopen("robot.INP","r",stdin);
    freopen("robot.OUT","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++) cin>>gas[i];
	cin>>m;
	for(int i = 1; i <= m; ++i) {
		int u, v, l, t;
		cin>>u>>v>>l>>t;
		--u; --v; c[u][v] = c[v][u] = t;
		g[u].push_back({v, l});
		g[v].push_back({u, l});
	}
}

void dijkstra() {
    vi d = vi(n, INF); d[0] = 0;
	priority_queue<ii, vii, greater<ii> > qu;
	qu.push({0, 0});
	while(!qu.empty()) {
		int du = qu.top().fi, u = qu.top().se; qu.pop();
		if(du!=d[u]) continue;
		TR(g[u],i) {
			int v =g[u][i].fi, l =g[u][i].se;
			if(du + l < d[v]) {
				t[v]=vi(1,u);
				d[v]=du+l;
				qu.push({d[v],v});
			}
			else
                if(du+l==d[v]) t[v].push_back(u);
		}
	}
}

bool bfs(int w) {
	queue<ii> qu; qu.push({n-1, w});
	while(!qu.empty()) {
		int u = qu.front().fi, e = qu.front().se; qu.pop();
		if(u == 0) return 1;
		TR(t[u], i) {
			int v=t[u][i];
			if(c[u][v] <= e)
			   {if(gas[v]) qu.push({v,w});
                else qu.push({v,e-c[u][v]});}
		}
	}
	return 0;
}

void xuli() {
	int lo = 0, hi = INF;
	while(lo < hi) {
		int mid = (lo+hi)/2;
		if(bfs(mid)) hi = mid; else lo = mid + 1;
	}
	cout<<lo;
}

int main() {

	nhap();
	dijkstra();
	xuli();
	return 0;
}
