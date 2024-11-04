#include<bits/stdc++.h>
using namespace std;
const int oo=1e9+1;
const int maxn=1e3+7;
const int maxm=1e4+7;
int n,m,a[maxn],res;
int l[maxn][maxm],cs[maxn];
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("doitien.inp","r",stdin);
    freopen("doitien.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
}
void tinh()
{

    for(int i=1;i<=n;i++) l[i][0]=0;
    for(int j=1;j<=m;j++) l[0][j]=oo;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i]>j) l[i][j]=l[i-1][j];
        else
            l[i][j]=min(l[i-1][j],1+l[i][j-a[i]]);
    }
}
void timkq()
{
    res=l[n][m];
}
int main()
{
    init();
    tinh();
    timkq();
    cout<<res<<'\n';
    return 0;
}

