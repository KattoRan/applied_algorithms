#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
long long n, a[N],sum[N], sm_odd = N, sm_even = 0;
long long res = numeric_limits<long long>::min(); // Khởi tạo giá trị tối thiểu

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> a[i];

    sum[0] = 0;

    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
    if (sum[1]%2 == 0)
    {
        res = max(res, sum[1]);
        sm_even = min(sm_even, sum[1]);
    }
    else
        sm_odd = min(sm_odd,sum[1]);
    for (int i = 2; i <= n; i++) {
        if (sum[i] % 2 == 0)
        {
            res = max(res, sum[i] - sm_even);
            sm_even = min(sm_even, sum[i]);
        }
        else
        {
            res = max(res, sum[i] - sm_odd);
            sm_odd = min(sm_odd, sum[i]);
        }
        //cout << sm_even << " " << sm_odd << endl;
    }

    if (res <= 0) {
        cout << "NOT_FOUND" << endl;
    } else {
        cout << res << endl;
    }

    return 0;
}
