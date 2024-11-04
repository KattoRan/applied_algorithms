#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define name "abc"
using namespace std;
const int maxn=1e6+3;
const int oo=1e9+1;
typedef pair<int,int>ii;
typedef long long ll;
ii a,b,c;
bool ok(ii a,ii b,ii c)
{
    int dx1=a.fi-c.fi;
    int dy1=a.se-c.se;
    int dx2=b.fi-c.fi;
    int dy2=b.se-c.se;
    if(dx1*dy2==dy1*dx2) return 0;
    return 1;
}
void enter()
{
    cin>>a.fi>>a.se>>b.fi>>b.se>>c.fi>>c.se;
    if(ok(a,b,c))
    {
        cout<<"YES";
        return;
    }
    cout<<"NO";
}
void solve()
{

}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    #ifndef ONLINE_JUDGE
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    #endif // ONLINE_JUDGE
    enter();
    solve();
    cerr<<"\ntime: "<<clock()*1000/CLOCKS_PER_SEC<<"ms";
}
