#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
const int M = 1e3 + 4;
const long long inf = 1e18;
const long long MOD = 1e9 + 7;


long long dp[M][M];
int n, k1, k2;

long long calc(int i, int k)
{
    if (i == n)
    {
        if (k == 0 || (k1 <= k && k <= k2)) return 1;
        else return 0;
    }
    long long &res = dp[i][k];
    if (res) return res;

    res = 0;
    if (k1 <= k && k <= k2) (res+= calc(i+1, 0))%= MOD;
    if (k < k2)  (res+= calc(i+1, k+1))%= MOD;

    return res;
}

int main() {
    ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k1 >> k2;
    memset(dp, 0 , sizeof dp);
    cout << (calc(0, 0) + calc(1, 0)) % MOD << '\n';
    return 0;
}

