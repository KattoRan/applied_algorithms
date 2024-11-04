#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
int n,m,k;
int a[maxn];
int f[maxn][maxn];
long long res,sum[maxn];
void xuli()
{
    sum[0]=0;
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+(long long)a[i];
    for(int i=1;i<=k;i++)
        for(int j=i*m;j<=n;j++)
    {
        int t=f[i-1][j-m]+sum[j]-sum[j-m];
        f[i][j]=max(f[i-1][j],t);
    }
    cout<<f[k][n];
}
int main()
{
    freopen("kseq.inp","r",stdin);
    freopen("kseq.out","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    xuli();
}
