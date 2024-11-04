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

const int N=4e3+7;
const int mod=1e9+7;

typedef long long ll;
typedef pair<int,int> ii;

int m,n,k;
int a[N],b[N];
int c[N][N],f[N][N];
int d[N],d1[N];

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

void ent()
{
    cin>>m>>n>>k;
    fu(i,1,m) cin>>a[i];
    fu(i,1,n) cin>>b[i];
    fu(i,1,m)
    {
        fu(j,1,n)
        {
            c[i][j]=((a[i]%k+b[j]%k)%k)+1;
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }


}

void solve()
{
    f[1][1]=1;
    fu(i,1,m)
    fu(j,1,n)
    {
         for(int k=1;k<=c[i][j];k++)
         {
             f[i][j+k]=(f[i][j+k]%mod+f[i][j]%mod)%mod;
             f[i+k][j]=(f[i+k][j]%mod+f[i][j]%mod)%mod;
         }
    }
    cout<<f[m][n];
}

catlan()
{
#define name ""
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    ent();
    solve();
}
