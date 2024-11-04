#include <bits/stdc++.h>
using namespace std;

const int oo=1e6+7;

typedef long long ll;
typedef pair<int,int> ii;

template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-')
    {
        tam=-1;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}

int n, m, k;
int res = oo;
vector<int> a[31];
int load[11], b[31][31], x[31];
bool check(int u, int v)
{
    for (int i = 1; i <= u; i++)
        if (x[i] == v && b[u][i]) return false;
    return true;
}
void solution()
{
    int res1 = load[1];
    for (int i = 2; i <= m; i++)
        res1 = max(res1,load[i]);
    res = min(res,res1);
}
void Try(int i)
{
    for (auto j : a[i])
        if (check(i,j))
    {
        x[i] = j;
        load[j]++;
        if (i == n) solution();
        else 
        {
            if (load[j] < res) Try(i+1);
        }
        load[j]--;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    read(m); read(n);
    for (int i = 1; i <= m; i++)
    {
        int kk; read(kk);
        for (int j = 1; j <= kk; j++)
        {
            int u; read(u);
            a[u].push_back(i);
        }
    }
    read(k);
    while (k--)
    {
        int u,v;
        read(u); read(v);
        b[u][v] = 1;
        b[v][u] = 1;
    }
    Try(1);
    cout << res;
    return 0;
}