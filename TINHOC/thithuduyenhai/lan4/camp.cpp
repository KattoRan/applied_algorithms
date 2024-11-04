#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
const int maxm=1e3+7;
const int oo=1e15;
int m,n,a[maxm*2],b[maxm*2],i,j;
long long  f[maxm][maxn][2];
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>m>>n;
    for(int i=1; i<=m; i++)
        cin>>a[i]>>b[i];
    for(int i=1; i<=n; i++)
        cin>>a[i+m]>>b[i+m];
    a[0]=b[0]=1e3;
}
long long  dist(long long i1,long long i2)
{
    return (a[i1]-a[i2])*(a[i1]-a[i2])+(b[i1]-b[i2])*(b[i1]-b[i2]);
}
void xuli()
{
   f[1][0][0]=0;
    for( i=2;i<=m;i++)
        f[i][0][0]=f[i-1][0][0]+dist(i-1,i);
    for( i=1;i<=m;i++)
        f[i][0][1]=oo;
    for( j=1;j<=n;j++)
    {
        f[0][j][0]=f[0][j][1]=oo;
    }
    for( i=1;i<=m;i++)
        for( j=1;j<=n;j++)
    {
        if(i==m&&j==0) continue;
        f[i][j][0]=min((f[i-1][j][0]+dist(i-1,i)),(f[i-1][j][1]+dist(i,j+m)));
        if(j==1) f[i][j][1]=f[i][j-1][0]+dist(j+m,i);
        else f[i][j][1]=min((f[i][j-1][0]+dist(j+m,i)),f[i][j-1][1]+dist(j+m,j+m-1));
    }
    cout<<f[m][n][0];
}
int main()
{
    init();
    xuli();
}
