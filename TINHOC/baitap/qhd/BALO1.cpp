#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int n,w,m[maxn],res,c[maxn];
int l[maxn][maxn],cs[maxn];
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BALO1.inp","r",stdin);
    freopen("BALO1.out","w",stdout);
    cin>>n>>w;
    for(int i=1;i<=n;i++) cin>>m[i];
    for(int i=1;i<=n;i++) cin>>c[i];
}
void tinh()
{

    for(int i=1;i<=n;i++) l[i][0]=0;
    for(int j=1;j<=w;j++) l[0][j]=0;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=w;j++)
    {
        l[i][j]=l[i-1][j];
        if(m[i]<=j)
            l[i][j]=max(l[i-1][j],c[i]+l[i-1][j-m[i]]);
    }
}
void timkq()
{
    res=l[n][w];
    int i,j;
    i=n;j=w;
    while(i>=1&&j>=1)
    {
        if( l[i][j]==c[i]+l[i-1][j-m[i]]) {cs[i]=1;j=j-m[i];}
        i--;
    }
}
int main()
{
    init();
    tinh();
    timkq();
    cout<<res<<'\n';
    for(int i=1;i<=n;i++) if(cs[i]==1) cout<<i<<" ";
    return 0;
}
