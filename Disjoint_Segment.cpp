#include<bits/stdc++.h>
#define all(vec) begin(vec),end(vec)
#define SZ(a) int(a.size())
using namespace std;
const int mn = 1e6 + 7;
const int mm = 1e3 + 4;
const long long inf = 1e18;
const long long MOD = 1e9 + 7;
using ll = long long;
int dp[mn];
vector<int>a[mn];
int n;

int main() {
    #define name ""
    ios_base :: sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // #ifndef ONLINE_JUDGE
    // freopen(name".inp","r",stdin);
    // freopen(name".out","w",stdout);
    // #endif // ONLINE_JUDGE

    cin >> n;
    for(int i = 1; i <= n; ++i) {
        int start, finish;
        cin >> start >> finish;

        a[start].push_back(finish);
    }   

    int Max = 0;

    for(int i = 0; i < mn; ++i) {
        for(auto finish: a[i]) {
            dp[finish] = max(dp[finish], Max + 1);
        }
        Max = max(Max, dp[i]);
    }

    cout << Max << '\n';


    // cerr<<"Running Time: "<<clock()/double(1000) <<"s\n";
    return 0;
}
