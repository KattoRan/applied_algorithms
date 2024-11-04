#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define bit(X,i) ((X>>i)&1)
#define on(X,i) (X|(1<<i))
#define off(X,i) (X^(1<<i))
#define dembit(X) __builtin_popcount(X)
using namespace std;

const int N=1e6+7;
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

int n,m;
vector<ii> a[N];
long long res = 0;
int d[N];
int main()
{
    read(n); read(m);
    for (int i =1; i <= m; i++)
    {
        int u,v,w;
        read(u); read(v); read(w);
        a[u].push_back({v,w});
        a[v].push_back({u,w});
    }
    //prim
    priority_queue<ii,vector<ii>,greater<ii> > q;
    for (int i = 1; i <= n; i++) d[i] = oo;
    d[1] = 0;
    q.push({0,1});
    while (!q.empty())
    {
        int u = q.top().se;
        int ww = q.top().fi;
        q.pop();
        if (d[u] != ww) continue;
        res += d[u];
        d[u] = 0;
        for (ii i : a[u])
        {
            int v = i.fi;
            int w = i.se;

            if (d[v] > w)
            {
                d[v] = w;
                q.push({d[v],v});
            }
        }
    }
    cout << res << '\n';
    return 0;

}