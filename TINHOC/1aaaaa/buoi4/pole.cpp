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

const int N=1e4+7;
const long long oo=1e18+7;

typedef long long ll;
typedef pair<int,int> ii;
int n,c,a[N];
ll res;
ll f[N][107];
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
    cin>>n>>c;
    fu(i,1,n) cin>>a[i];
    fu(i,2,n)
    res+=c*abs(a[i]-a[i-1]);
}

void solve()
{
    int amax=*max_element(a+1,a+n+1);
    fu(i,0,amax-a[1])
    f[1][i]=i*i;
    fu(i,2,n)
    {
        fu(j,0,amax-a[i])
        {
            f[i][j]=oo;
            fu(t,0,amax-a[i-1])
            {
                f[i][j]=min(f[i][j],(f[i-1][t]+j*j)+c*abs(a[i]+j-a[i-1]-t));
            }
        }
    }
    res=oo;
    fu(i,0,amax-a[n])
    res=min(res,f[n][i]);
    cout<<res;
}

catlan()
{
#define name "pole"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    ent();
    solve();
}
