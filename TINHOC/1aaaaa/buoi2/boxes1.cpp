#include <bits/stdc++.h>
#define reset(x, val) memset((x), (val), sizeof (x))
#define bit(X, i) (((X) >> (i)) & 1)
#define all(X) (X).begin(), (X).end()
#define on(X,i) (X|(1<<i))
#define off(X,i) (X^(1<<i))
#define cntbit(X) __builtin_popcount(X)
#define pb push_back
#define ep emplace_back
#define fi first
#define se second
using namespace std;

const char ginp[]="BOXES.INP";
const char gout[]="BOXES.OUT";

void debug_out()
{
    cerr << '\n';
}
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T)
{
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

void read() {}
template <typename Head, typename ...Tail>
void read(Head &H, Tail &...T)
{
    register char c;
    bool sign = 0;
    for (c = getchar(); !isdigit(c); c = getchar())
        if (c == '-')
            sign = !sign;
    H = c - '0';
    for (c = getchar();  isdigit(c); c = getchar())
        H = H * 10 + c - '0';
    if (sign)
        H = -H;
    read(T...);
}

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef vector <int> vi;
typedef vector <ii> vii;

mt19937 rd(chrono :: steady_clock :: now().time_since_epoch().count());
#define rand rd
ll Rand(ll l, ll h)
{
    return l + rand() % (h - l + 1);
}

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

const int N = 25;
const int M = 1e6 + 1e5;
const int oo = 1e9 + 7;

int n,k;
ll c[N][N];
ll dp[M];

void enter()
{
    cin>>n>>k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin>>c[i][j];
}

ll calc(int mask)
{
    if (cntbit(mask) <= k)
        return 0;
    if (dp[mask] != -1)
        return dp[mask];
    dp[mask] = 1e18;
    for (int i = 0; i < n; i++)
        if (bit(mask,i))
        {
            for (int j = 0; j < n; j++)
                if (bit(mask,j) && j != i)
                    dp[mask] = min(dp[mask], calc(mask-(1<<j))+c[j][i]);
        }
    return dp[mask];
}

void solve()
{
//    for (int i = 0; i < n; i++)
//    if (bit((1<<n)-1,i)) cout<<i<<" ";
    reset(dp,-1);
    cout<<calc((1<<n)-1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifndef ONLINE_JUDGE
    //freopen(ginp, "r", stdin);
    //freopen(gout, "w", stdout);

#endif // ONLINE_JUDGE

    enter();
    solve();

    cerr << "\nTime : " << clock() << "ms\n";
    return 0;
}
