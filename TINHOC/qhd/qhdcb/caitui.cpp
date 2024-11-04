#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int n,m,a[maxn],res,c[maxn];
int l[maxn][maxn],cs[maxn];
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("caitui.inp","r",stdin);
    freopen("caitui.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
}
void tinh()
{

    for(int i=1;i<=n;i++) l[i][0]=0;
    for(int j=1;j<=m;j++) l[0][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        l[i][j]=l[i-1][j];
        if(a[i]<=j)
            l[i][j]=max(l[i-1][j],c[i]+l[i][j-a[i]]);
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

