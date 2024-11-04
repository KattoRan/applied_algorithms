#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+7;
int n,d[N];
int dem = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> d[i];
    sort(d+1,d+n+1);
    int cnt_time = 0;
    for (int i = n; i >= 1; i--)
        {
            //cout << cnt_time << " " << d[i] << endl;
            if (cnt_time + d[i] > dem) dem = cnt_time + d[i];
            cnt_time++;
        }
    cout << dem;
    return 0;
}
