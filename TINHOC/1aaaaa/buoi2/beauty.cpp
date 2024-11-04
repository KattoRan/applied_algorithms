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
int n,a[N];
ll s[N],res;

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
   fu(i,1,n)
   read(a[i]),s[i]=s[i-1]+a[i];
}

void solve()
{
   int vtl=1,vtc=0;
   fu(i,4,n)
   if(i%2)
   {
       if(s[vtl]>s[i-4]) vtl=i-4;
       res=max(res,s[i]-s[vtl]);
   }
   else
   {
       if(s[vtc]>s[i-4]) vtc=i-4;
       res=max(res,s[i]-s[vtc]);
   }
   cout<<res;
}

catlan()
{
    #define name "beauty"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    ent();
    solve();
}
