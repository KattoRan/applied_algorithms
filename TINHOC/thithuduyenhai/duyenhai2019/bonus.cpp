#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
long long m,n,k,x,y,u,v,res;
long long a[maxn][maxn],t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("bonus.inp","r",stdin);
    freopen("bonus.out","w",stdout);
    cin>>m>>n>>k>>x>>y>>u>>v;
    t=0;
    a[1][1]=1;
    for(int j=2; j<=n; j++)
        a[1][j]=a[1][j-1]*k;
    for(int i=2; i<=m; i++)
        for(int j=1; j<=n; j++)
            if(j==1)
                a[i][j]=a[i-1][n]*k;
            else
                a[i][j]=a[i][j-1]*k;
    for(int i=x; i<=u; i++)
        for(int j=y; j<=v; j++)
            t+=a[i][j];
    res=t%111539768;
    cout<<res;
    return 0;
}
