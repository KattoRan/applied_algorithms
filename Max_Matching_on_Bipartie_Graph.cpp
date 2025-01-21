#include<bits/stdc++.h>
#define up(i,a,b) for(int i = a ; i <= b ; ++i)
#define ep emplace_back
#define SZ(a) int(a.size())
#define rep(i,a) for(int i : a)
using namespace std;
const int N = 1e6+7;
int Px[N],Py[N],trc[N];
int n,m;
vector<int>a[N];
int bfs(){
	up(i,1,m)trc[i] = 0;
	queue<int>q;
	up(i,1,n)if(!Px[i])q.push(i);
	while(SZ(q)){
		int x = q.front();
		q.pop();
		rep(y,a[x]){
			if(!trc[y]){
				trc[y] = x;
				if(!Py[y])return y;
				q.push(Py[y]);
			}
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;	
	for (int u = 1; u <= n; u++)
	{
		int k; cin >> k;
		for (int j = 1; j <= k; j++)
		{
			int v; cin >> v;
			a[u].emplace_back(v);
		}
	}
	up(i,1,n){
		rep(j,a[i]){
			if(!Py[j]){
				Px[i] = j;Py[j] = i;break;
			}
		}
	}
	for(int y = bfs();y;y = bfs()){
		while(trc[y]){
			int x = trc[y],z = Px[x];
			Px[x] = y;Py[y] = x;
			y = z;
		}
	}
	int ans = 0;
	up(i,1,n)if(Px[i]) ++ans;
	cout << ans << '\n';
	return 0;
}