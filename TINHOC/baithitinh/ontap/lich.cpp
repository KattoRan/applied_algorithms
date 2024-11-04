// Cat \\
||*---*||
#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
using namespace std;
const int N=1e6+7;
typedef long long ll;
typedef pair<int,int> ii;
ii p[N],p1[N],c[N];
int x,y,n,bd,kt;

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

bool cmp1(ii a,ii b)
{
    return a.se<b.se;
}
bool cmp2(ii a,ii b)
{
    if(a.se==b.se) return a.fi<b.fi;
    return a.se>b.se;
}
void nhap()
{
    int a,b;
    while(cin>>a>>b)
    {
       n++;
       if(a<=b) x++,p[x].fi=a,p[x].se=b;
       else y++,p1[y].fi=a,p1[y].se=b;
    }
    sort(p+1,p+x+1,cmp1);
    sort(p1+1,p+y+1,cmp2);
}

void solve()
{
    fu(i,1,x) c[i].fi=p[i].fi,c[i].se=p[i].se;
    fu(i,1,y) c[i+x].fi=p[i].fi,c[i+x].se=p[i].se;
    fu(i,1,n)
    {
        bd=bd+c[i].fi;
        kt=bd+c[i].se;
    }
    cout<<kt;
}

main()
{
    #define name "a"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    nhap();
    solve();
}
