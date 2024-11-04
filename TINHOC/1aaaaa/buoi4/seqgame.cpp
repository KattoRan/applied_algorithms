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
const long long oo=1e18+7;

typedef long long ll;
typedef pair<int,int> ii;
int m,n,k;
ll a[N],b[N],s[N],res[N];
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
   read(m);
   read(n);
   read(k);
   fu(i,1,m)
   read(a[i]);
   fu(i,1,n)
   read(b[i]);
   fu(i,1,k)
   read(s[i]),res[i]=oo;
}

void solve()
{
   sort(a+1,a+m+1);
   a[0]=a[m+1]=1e10+7;
   fu(i,1,k)
   fu(j,1,n)
   {
       ll x=s[i]-b[j];
       int cc=lower_bound(a+1,a+m+1,x)-a;
       if(x==a[cc]) res[i]=0;
       else
        {res[i]=min(abs(a[cc-1]+b[j]-s[i]),res[i]);
        res[i]=min(res[i],abs(a[cc]+b[j]-s[i]));}
   }
   fu(i,1,k) cout<<res[i]<<'\n';
}
void solve2()
{
    int l,r;
    sort(a+1,a+m+1);
    sort(b+1,b+n+1);
    fu(i,1,k)
    {
        ll res1=oo;
        l=1;
        r=n;
        while(l<=m&&r>0)
        {
            res1=min(res1,abs(1ll*(s[i]-a[l]-b[r])));
            if(res1==0)
                break;
            else
                if(a[l]+b[r]>s[i]) r--;
                else l++;
        }
        cout<<res1<<"\n";
    }

}
catlan()
{
    #define name "seqgame"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    ent();
    if(k<=10)solve();
    else solve2();
}
