#include <bits/stdc++.h>
using namespace std;
const int mn = 1e6 + 7;
const int mm = 1e3 + 4;
const long long inf = 1e18;
const long long MOD = 1e9 + 7;
int n;
int a[mn];
int temp[mn];

long long merge(int l, int mid, int r)
{
	int i = l;
	int j = mid+1;
	int k = l;
	long long inv_count = 0;
	while((i<=mid) && (j <= r))
	{
		if (a[i] <= a[j]) temp[k++] = a[i++];
		else
		{
			temp[k++] = a[j++];
			inv_count = (inv_count + (mid - i +1))%MOD;
		} 
	}
	while(i <= mid) temp[k++] = a[i++];
	while(j <= r) temp[k++] = a[j++];
	for (int i = l; i <= r; i++) a[i] = temp[i];
	return inv_count;
}
long long Merge_sort(int l, int r)
{
	int inv_count = 0;
	if (l < r)
	{
		int mid = (l+r)/2;
		inv_count = (inv_count + Merge_sort(l,mid))%MOD;
		inv_count = (inv_count + Merge_sort(mid+1,r))%MOD;
		inv_count = (inv_count + merge(l,mid,r))%MOD;
	}
	return inv_count;
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	long long inv_count = Merge_sort(1,n);
	cout << inv_count << endl;
	return 0;
}