// Cat \\
||*---*||
#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define catlan main
#define on(X,i) (X|(1<<i))
#define off(X,i) (X^(1<<i))
#define bit(X,i) ((X>>i)&1)
#define dembit(X) __builtin_popcount(X)
using namespace std;

const int N=2e6+7;

typedef long long ll;
typedef pair<int,int> ii;
int n,k;
ll c[25][25],f[N];

template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-')
        c=getchar();
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

ll solve(int m)
{
    if(dembit(m)<=k)
        return 0;
    if(f[m]!=-1)
        return f[m];
    f[m]=1e18+7;
    for(int i=0; i<n; i++)
        if(bit(m,i))
            for(int j=0; j<n; j++)
                if(bit(m,j)&&j!=i)
                    f[m]=min(f[m],solve(m-(1<<j))+c[j][i]);
    return f[m];
}

void ent()
{
    memset(f,-1,sizeof f);
    cin>>n>>k;
    for(int i=0;i<n;i++)
    for(int j=0;j<n;j++) cin>>c[i][j];
    cout<<solve((1<<n)-1);
}

catlan()
{
#define name "boxes"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    ent();
}
