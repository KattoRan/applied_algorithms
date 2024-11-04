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
#define next __next
using namespace std;

const char ginp[]="COMPUTER.INP";
const char gout[]="COMPUTER.OUT";

void debug_out() { cerr << '\n'; }
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
        if (c == '-') sign = !sign;
    H = c - '0';
    for (c = getchar();  isdigit(c); c = getchar())
        H = H * 10 + c - '0';
    if (sign) H = -H;
    read(T...);
}

typedef long long ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;
typedef vector <int> vi;
typedef vector <ii> vii;

mt19937 rd(chrono :: steady_clock :: now().time_since_epoch().count());
#define rand rd
ll Rand(ll l, ll h) { return l + rand() % (h - l + 1); }

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};

const int N = 1e3 + 5;
const int oo = 1e9 + 7;

int x,a,b,y,n;
ii f[N][N];

void enter()
{
    cin>>x>>a>>y>>b>>n;
}

ii next(ii a, int x, int v)
{
    a.se += v;
    return (a.se >= x ? ii(a.fi+1, 0) : a);
}

bool check(int val)
{
    ///min cost val;
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++) f[i][j] = ii(0,0);
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++)
        {
            if (i < x) f[i+1][j] = max(f[i+1][j], next(f[i][j], val, a));
            if (j < y) f[i][j+1] = max(f[i][j+1], next(f[i][j], val, b));
        }
    for (int i = 0; i <= x; i++)
        for (int j = 0; j <= y; j++) if (f[i][j].fi == n) return 1;
    return 0;
}

void solve()
{
    int L, R, ans;
    L = 0; R = 1e9;
    while (L <= R)
    {
        int m = (L+R)/2;
        if (check(m))
        {
            ans = m;
            L = m + 1;
        }
        else R = m - 1;
    }
    cout<<ans;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
    freopen(ginp, "r", stdin);
    freopen(gout, "w", stdout);
    #endif // ONLINE_JUDGE

    enter();
    solve();

    cerr << "\nTime : " << clock() << "ms\n";
    return 0;
}
