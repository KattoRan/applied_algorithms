#include <bits/stdc++.h>
#define maxn 100005
#define oo 1.0e15
#define task "dcva"
using namespace std;

int n, c, a[maxn], b[maxn];
int dp[maxn];
int k;
int p[maxn], q[maxn];
double x[maxn];

bool ok (int i)
{
    if (b[i] == p[k])
        return false;
    double xM = 1.0 * (dp[i] - q[k]) / (p[k] - b[i]);
    double xN = 1.0 * (dp[i] - q[k - 1]) / (p[k - 1] - b[i]);
    return (xN < xM);
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>c;
    for (int i = 1; i <= n; ++i)
        cin>>a[i];
    for (int i = 1; i <= n; ++i)
        cin>>b[i];
    dp[1] = c;
    k = 1;
    x[1] = -oo, p[1] = b[1], q[1] = dp[1];
    int u = 1;
    for (int i = 2; i <= n; ++i)
    {
        while (u <= k && x[u] <= a[i])
            ++u;
        --u;
        dp[i] = q[u] + p[u] * a[i];
        if (b[i] == p[k] && dp[i] >= q[k])
            continue;
        while (k > 1 && !ok (i))
            --k;
        if (u > k)
            u = k;
        if (k == 1 && p[1] == b[i])
            q[1] = dp[i];
        else
        {
            p[++k] = b[i], q[k] = dp[i];
            x[k] = 1.0 * (q[k] - q[k - 1]) / (p[k - 1] - p[k]);
        }
    }
    cout<<dp[n];
    return 0;
}
