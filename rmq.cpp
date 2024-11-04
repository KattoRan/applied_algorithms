#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define catlan main
#define bit(X,i) ((X>>i)&1)
#define on(X,i) (X|(1<<i))
#define off(X,i) (X^(1<<i))
#define dembit(X) __builtin_popcount(X)
using namespace std;

const int N = 1e3 + 7;
const int M = 1e6 + 7;

typedef long long ll;
typedef pair<int,int> ii;

template <typename T> inline void read(T &x)
{
    x = 0;
    char c = getchar();
    int sign = 1;
    while(!isdigit(c) && c != '-') c = getchar();
    if(c == '-')
    {
        sign = -1;
        c = getchar();
    }
    while(isdigit(c))
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    x *= sign;
}

long long m[M][21], a[M], n;

void RMQ(int n)
{
    for(int i = 0; i < n; i++) m[i][0] = i;
    for(int j = 1; (1 << j) <= n; j++)
    {
        for(int i = 0; i + (1 << j) - 1 < n; i++)
        {
            if(a[m[i][j-1]] < a[m[i + (1 << (j-1))][j-1]])
                m[i][j] = m[i][j-1];
            else
                m[i][j] = m[i + (1 << (j-1))][j-1];
        }
    }
}

void ent()
{
    read(n);
    fu(i, 0, n-1) read(a[i]);
}

void solve()
{
    int q;
    read(q);
    long long Q = 0;
    while(q--)
    {
        int u, v;
        read(u); read(v);
        int k = floor(log2(v - u + 1)); // Tính toán k
        if(a[m[u][k]] <= a[m[v - (1 << k) + 1][k]]) Q+=a[m[u][k]];
        else Q+=a[m[v - (1 << k) + 1][k]];
    }
    cout << Q << endl;
}

int catlan()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ent();
    RMQ(n);
    solve();
    return 0;
}
