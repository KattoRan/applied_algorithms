#include <bits/stdc++.h>
using namespace std;
const int mn = 1e6 + 7;
const int mm = 1e3 + 4;
const long long inf = 1e18;
const long long MOD = 1e9 + 7;

int q,n,c;
int a[mn];
int check(int dis)
{
	int sl = 1;
	int i = 1, j = 2;
	while (i < n)
	{
		while(j <= n && a[j] - a[i] < dis) j++;
		if (j <= n) sl++;
		if (sl >= c) return 1;
		i = j;
		j++;
	}
	return 0;
}
int Max_Distance(int n)
{
	int l = 0;
	int r = a[n] - a[1];
	while (l <= r)
	{
		int mid = (l+r)/2;
		if (check(mid)) l = mid+1;
		else r = mid-1;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> q;
	while (q--)
	{
		cin >> n >> c;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1,a+n+1);
		cout << Max_Distance(n) << "\n";
	}
}