// Cat \\
||*---*||
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

const int N=1e6+7;
const int M=1e3+5;

typedef long long ll;
typedef pair<int,int> ii;
ll m,n,k,d[N];
ll f[M][M],g[M][M];

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

void ent()
{
  read(n);
  read(m);
  read(k);
  fu(i,1,n)
  {
      int x;
      read(x);
      d[x]++;
  }
}

void solve()
{
   fu(i,1,m)
   fu(j,0,k)
   {
       ll a,b,c;
       a=d[i]/(j+1);
       b=d[i]-a*(j+1);
       c=j+1-b;
       f[i][j]=a*(a+1)*c/2+(a+1)*(a+2)*b/2;
   }
   fu(i,0,k) g[1][i]=f[1][i];
   fu(i,2,m)
   fu(j,0,k)
   {
       g[i][j]=g[i-1][j]+f[i][0];
       fu(h,1,j)
       g[i][j]=min(g[i][j],g[i-1][j-h]+f[i][h]);
   }
   cout<<g[m][k];
}

catlan()
{
    #define name "noise"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    ent();
    solve();
}
