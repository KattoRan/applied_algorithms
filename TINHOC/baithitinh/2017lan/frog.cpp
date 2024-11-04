#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=2007;
const int K=1e5+7;
int m,n,k,d;
int a[N][N];
int ma,b[K];
long long res;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("frog.inp","r",stdin);
    freopen("frog.out","w",stdout);
    cin>>m>>n>>k;
    fu(i,1,m)
    fu(j,1,n) cin>>a[i][j],ma=max(ma,a[i][j]);
    fu(i,1,m)
        fu(j,1,n)
            b[a[i][j]]++;
    sort(b+1,b+ma+1);
    for(int i=ma; i>=ma-k+1; i--)
        res+=b[i];
    cout<<res;
}
