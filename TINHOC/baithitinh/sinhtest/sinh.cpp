#include<bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define up(i,a,b) for(int i=a;i<=b;i++)
#define dw(i,a,b) for(int i=a;i>=b;i--)
#define all(a) a.begin(),a.end()
#define rall(a) a.rbegin(),a.rend()
#define FOR(i,n) for(int i=0;i<n;++i)
#define REP(i,n) for(int i=n-1;i>=0;--i)
const int mn=1e6+7;
const int mm=1e4+5;
const int mod=1e9+7;
using namespace std;

int n;
ll f[mn],s,a[mn];
set<ll>mse;

int main()
{
#define name "expression"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
//    freopen(name".inp","r",stdin);
    freopen(name".inp","w",stdout);

    srand(time(NULL));
    int n=rand()%20;
    cout<<n<<'\n';
    up(i,1,n)cout<<rand()%100+100<<" ";

    cerr<<"\ntime: "<<clock()/(double(1000))<<"s\n";
    return 0;
}
