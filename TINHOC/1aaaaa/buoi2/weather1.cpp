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

const char ginp[]="WEATHER.INP";
const char gout[]="WEATHER.OUT";

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

const int N = 1e2 + 5;
const int oo = 1e9 + 7;

int n,m;
vi ke[N];
int f[N], low[N], num[N];
vii bridge;

void enter()
{
    cin>>n>>m;
    for (int i = 1; i <= m; i++)
    {
        int u,v;
        cin>>u>>v;
        ke[u].pb(v); ke[v].pb(u);
    }
}

void dfs(int u, int p)
{
    f[u] = 1;
    low[u] = num[u] = ++num[0];
    for (int v : ke[u])
    {
        if (v == p) continue;
        if (num[v]) low[u] = min(low[u], num[v]);
        else
        {
            dfs(v,u);
            low[u] = min(low[u], low[v]);
            f[u] += f[v];
            if (low[v] >= num[v]) bridge.pb(ii(u,v));
        }
    }
}

void solve()
{
    dfs(1,0);
    ll res = 0;
    for (ii c : bridge) res += f[c.se] * (n - f[c.se]);
    cout<<res;
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
