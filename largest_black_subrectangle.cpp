#include <bits/stdc++.h>
using namespace std;

const int N = 1e3+7;
int a[N][N],n,m;
int h[N][N], l[N], r[N];

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			if (a[i][j] == 1)
				h[i][j] = h[i-1][j] + 1;
			else
				h[i][j] = 0;
	/*for (int i = 1; i <= n; i++){
		for (int j = 1; j <= m; j++)
			cout << h[i][j] << " ";
		cout << '\n';}*/
	long long ans=0;
	for (int i = 1; i <= n; i++)
		{
			stack<int> q;
			for (int j = 1; j <= m+1; j++)
			{
				while (q.size() && h[i][j] < h[i][q.top()])  r[q.top()]=j, q.pop();
				q.push(j);
			}
			while (q.size()) q.pop();
			for (int j = m; j >= 0; j--)
			{
				while (q.size() && h[i][j] < h[i][q.top()])  l[q.top()]=j, q.pop();
				q.push(j);
			}
			long long res = 0;
			for(int j = 1; j <= m; j++)
			{
				//cout << i << " " << j << " " << h[i][j] << " " << r[j] << " " << l[j] << endl;
				res = max(res,(long long) (r[j]-l[j]-1)*h[i][j]);
			}
			ans = max(ans,res);
		}
	cout << ans;
	return 0;
}