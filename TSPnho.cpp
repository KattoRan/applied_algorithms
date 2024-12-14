#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9+7;

int n;
int a[25][25], cmin = oo, f = 0;
int dx[25],x[25];
int res = oo;

void print()
{
	res = min(res,f+a[x[n]][1]);
}

void Try(int i)
{
	if (i == 1) {x[i] = 1; Try(i+1);}
	for (int j = 2; j <= n; j++)
		if(!dx[j])
	{
		x[i] = j;
		f+=a[x[i-1]][j];
		dx[j] = 1;
		if (i == n) print();
		else
		{
			if (f + (n-i+1) < res) Try(i+1);
		}
		dx[j] = 0;
		f-=a[x[i-1]][j];
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {cin >> a[i][j]; cmin=min(cmin,a[i][j]);}
	Try(1);
	cout << res;
	return 0;
}