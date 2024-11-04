#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
int n,a[maxn],f[maxn],res;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("NKJUMP.inp","r",stdin);
    //freopen("NKJUMP.out","w",stdout);
    cin >> n;
    for (int i=1; i<=n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    int res = 0;
    for(int i=1; i<=n; i++)
        f[i]=1;
    f[0]=0;
    for (int i=3; i<=n; i++)
    {
        for (int j=i-1; j>=2; j--)
        {
            int k=lower_bound(a+1,a+j,a[i]-a[j])-a;
            if(k!=j&&a[k]==a[i]-a[j])
            {
                f[i] = max(f[i], f[j]+1);
                f[i] = max(f[i], f[k]+1);
            }
        }
        res = max(res, f[i]);
    }
    cout << res;
    return 0;
}
