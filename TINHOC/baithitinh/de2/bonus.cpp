#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e3+7;
int n,k;
int a[N][N];
long long s[N][N],res;
main()
{
    #define name "bonus"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>n>>k;
    fu(i,1,n)
    fu(j,1,n) cin>>a[i][j];
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++) s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
    for(int i=k;i<=n;i++)
        for(int j=k;j<=n;j++)
        res=max(res,s[i][j]-s[i][j-k]-s[i-k][j]+s[i-k][j-k]);
    cout<<res;
}
