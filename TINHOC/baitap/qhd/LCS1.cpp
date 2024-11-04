#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int n,m,a[maxn],res,b[maxn];
int l[maxn][maxn],cs1[maxn],cs2[maxn];
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("LCS.inp","r",stdin);
    freopen("LCS.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++) cin>>a[i];
    for(int j=1;j<=n;j++) cin>>b[j];
}
void tinh()
{
    for(int i=1;i<=n;i++) l[0][i]=0;
    for(int i=1;i<=m;i++) l[i][0]=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
    {
        if(a[i]==b[j]) l[i][j]=l[i-1][j-1]+1;
        else l[i][j]=max(l[i-1][j],l[i][j-1]);
    }
}
void timkq()
{
    res=l[m][n];
    cout<<res<<'\n';
    int i,j,d=0;
    i=m;j=n;
    while(i>=1&&j>=1)
    {
        if(a[i]==b[j]) {d++;cs1[d]=i;cs2[d]=j;i--;j--;}
        else
           {
            if(l[i][j]==l[i-1][j]) i--;
            else j--;
           }
    }
    for(int i=d;i>=1;i--) cout<<cs1[i]<<" ";
    cout<<'\n';
    for(int i=d;i>=1;i--) cout<<cs2[i]<<" ";
}
int main()
{
    init();
    tinh();
    timkq();
    return 0;
}
