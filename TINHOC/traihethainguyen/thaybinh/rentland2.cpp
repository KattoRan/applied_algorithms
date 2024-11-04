#include <bits/stdc++.h>
#define maxn 50005
#define ft first
#define sc second
#define oo 1.0e15

using namespace std;
typedef pair<int, int> II;

int n, a[maxn], b[maxn];
int64_t f[maxn];
double x[maxn];
int p[maxn];
int64_t q[maxn];
int k;

bool ok (int i) {
    if (b[i + 1] == p[k])
        return false;
    double xM = 1.0 * (f[i] - q[k]) / (p[k] - b[i + 1]);
    double xN = 1.0 * (f[i] - q[k - 1]) / (p[k - 1] - b[i + 1]);
    return (xN < xM);
}

II rec[maxn];
int dd[maxn];
int main() {
    freopen ("RENTLAND.inp", "r", stdin);
    freopen ("RENTLAND.out", "w", stdout);
    scanf ("%d", &n);
    for (int i = 1; i <= n; ++i) {
        int u, v;
        scanf ("%d %d", &u, &v);
        rec[i] = {u, v};
    }
    sort (rec + 1, rec + n + 1);
    int bmax = rec[n].sc;
    for (int i = n - 1; i >= 1; --i) {
        if (rec[i].sc <= bmax)
            dd[i] = 1;
        else
            bmax = rec[i].sc;
    }
    int n1 = 0;
    for (int i = 1; i <= n; ++i)
        if (dd[i] == 0) {
            ++n1;
            a[n1] = rec[i].ft;
            b[n1] = rec[i].sc;
        }
    n = n1;
    b[n + 1] = 0;

    f[0] = 0;
    k = 0;
    x[0] = -oo, p[0] = b[1], q[0] = f[0];
    int u = 0;
    for (int i = 1; i <= n; ++i) {
        while (u <= k && x[u] <= a[i])
            ++u;
        --u;
        f[i] = q[u] + 1LL * p[u] * a[i];
        if (b[i + 1] == p[k] && f[i] >= q[k])
            continue;
        while (k >= 0 && !ok (i))
            --k;
        p[++k] = b[i + 1];
        q[k] = f[i];
        x[k] = 1.0 * (q[k - 1] - q[k]) / (p[k] - p[k - 1]);
    }
    printf ("%I64d", f[n]);
}
