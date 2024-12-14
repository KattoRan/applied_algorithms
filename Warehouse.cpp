#include<bits/stdc++.h>
#define all(vec) begin(vec),end(vec)
#define SZ(a) int(a.size())
using namespace std;
const int N = 1e6 + 7;
const int M = 1e3 + 4;
const long long inf = 1e18;
const long long MOD = 1e9 + 7;
using ll = long long;

int n, T, D, a[N], _t[N];
long long dp[2000][200][20];

long long calc(int i, int t, int d) {
   if(i == n+1) {
      if(t <= T)return 0;
      return -inf;
   }
   long long &res = dp[i][t][d];
   if(~res)return res;
   res = 0;

   if(d < D) {
      res = max(res, calc(i+1, t, d+1));
   }

   if(t + _t[i] <= T) {
      res = max(res, calc(i+1, t + _t[i], 1) + a[i]);
   }

   return res;
}

int main() {
   #define name ""
   ios_base :: sync_with_stdio(NULL);
   cin.tie(nullptr);
   cout.tie(nullptr);
  // #ifndef ONLINE_JUDGE
  // freopen(name".inp","r",stdin);
  // freopen(name".out","w",stdout);
  // #endif // ONLINE_JUDGE

   cin >> n >> T >> D;  
   for(int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   for(int i = 1; i <= n; ++i) {
      cin >> _t[i];
   }

   memset(dp, -1, sizeof dp);

   ll ans = 0;
   for(int i = 1; i <= n; ++i) {
      ans = max(ans, calc(i,0,0));
   }
   cout << ans << '\n';

    // cerr<<"Running Time: "<<clock()/double(1000) <<"s\n";
   return 0;
}
/*
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7;
const int M = 1e3 + 4;
const long long inf = 1e18;
const long long MOD = 1e9 + 7;

int n, T, D, a[N], t[N];
long long f[2000][2000];
long long ans;

void calc()
{
   for (int i = 1; i <= n; i++)
    {
        for (int k = t[i]; k <= T; k++)
            {
                for (int j = max(0,i-D); j <= i-1; j++)
                    f[i][k] = max(f[i][k], f[j][k-t[i]] + a[i]);
                ans = max (ans, f[i][k]);
            }
    }
}

int main() {
   #define name "a"
   ios_base :: sync_with_stdio(NULL);
   cin.tie(nullptr);
   cout.tie(nullptr);
  // #ifndef ONLINE_JUDGE
  //freopen(name".inp","r",stdin);
  // freopen(name".out","w",stdout);
  // #endif // ONLINE_JUDGE

   cin >> n >> T >> D;  
   for(int i = 1; i <= n; ++i) {
      cin >> a[i];
   }
   for(int i = 1; i <= n; ++i) {
      cin >> t[i];
   }
   calc();
   cout << ans << '\n';
   return 0;
}
*/