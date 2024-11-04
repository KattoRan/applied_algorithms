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

typedef long long ll;
typedef pair<int,int> ii;
ll n,res,f[N];

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

void sang()
{
    f[0]=1;
    f[1]=1;
    for(int i=2;i*i<=1000006;i++)
        if(!f[i])
        for(int j=i*i;j<=1000006;j+=i)
        if(!f[j]) f[j]=1;
    int k=0;
    fu(i,2,1000006)
    if(!f[i])
    {
        k++;
        f[k]=i;
    }
}

void solve(int i,int su,ll m)
{
    if(su>n) return;
    if(su==n) res=min(res,m);
    for(int j=1;j<=1000000;j++)
    {
        if(m*f[i]>res) break;
        m=m*f[i];
        solve(i+1,su*(j+1),m);
    }
}

void ent()
{
   cin>>n;
   sang();
   res=1e18+1;
   solve(1,1,1);
   cout<<res;
}

catlan()
{
    #define name "divisor"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    ent();
    //solve();
}
