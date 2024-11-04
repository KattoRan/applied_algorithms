//C++
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

int a[N],n;
long long sum[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            sum[i] = sum[i-1] + a[i];
        }
    int q;
    cin >> q;
    while(q--)
    {
        int u,v;
        cin >> u >> v;
        cout << sum[v] - sum[u-1] << endl;
    }
    return 0;
}
