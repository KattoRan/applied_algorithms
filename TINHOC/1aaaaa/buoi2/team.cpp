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
int n;
ll res;
int a[N],b[N];

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
    read(n);
}

void solve()
{
    res=1e18;
    int vt=0;
    fu(i,1,n)
    {
        read(a[i]),read(b[i]);
        if(a[i]<res)
            res=a[i],vt=i;
    }
    //b[vt]=1e9+7;
    sort(b+1,b+n+1);
    fu(i,1,n)
    {
        cout<<res<<'\n';
        res+=b[i];
    }
}

catlan()
{
#define name "team"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    ent();
    solve();
}
