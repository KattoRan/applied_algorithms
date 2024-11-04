#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int a[maxn][maxn],m,n,l[maxn][maxn];
int res,k;
void init()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     freopen("RBDR.inp","r",stdin);
     freopen("RBDR.out","w",stdout);
    cin>>m>>n;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
            cin>>a[i][j];
}
void tinh()
{   for(int i=1;i<=m;i++) l[i][0]=0;
    for(int j=1; j<=n;j++)
        l[0][j]=0;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        {
            k=max(l[i-1][j-1],l[i-1][j]);
            l[i][j]=max(k,l[i-1][j+1])+a[i][j];
        }
    res=l[m][1];
    for(int j=2; j<=n; j++)
        if(l[m][j]>res)
            res=l[m][j];
}
int main()
{
    init();
    tinh();
    cout<<res;
    return 0;
}
