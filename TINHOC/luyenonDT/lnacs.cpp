#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define task "lnacs"
using namespace std;
const int N=1e3+7;
typedef long long ll;
int n,m;
int a[N],b[N],f[N][N];

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>m>>n;
    fu(i,1,m) cin>>a[i];
    fu(i,1,n) cin>>b[i];
    if(a[1]==b[1]) f[1][1]=1;
    else f[1][1]=0;
    fu(i,2,m)
    fu(j,2,n)
    {
            if(a[i]==b[j]) f[i][j]=f[i-2][j-2]+1;
            else
                f[i][j]=max(f[i-1][j],f[i][j-1]);
    }
    cout<<f[m][n];

}
