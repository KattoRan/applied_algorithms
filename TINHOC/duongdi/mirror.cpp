#include<bits/stdc++.h>
using namespace std;

const int N=100;
const int dx[5]={0,0,-1,0,1};
const int dy[5]={0,-1,0,1,0};

int n,d,cx[N][N],b[N][N];
char a[N][N];
long long res;

void dfs(int x,int y)
{
    cx[x][y]=0;
    for(int i=1;i<=4;i++)
    {
        int u=x+dx[i];
        int v=y+dy[i];
        if(b[u][v]==1) d++;
        if(b[u][v]==0&&cx[u][v]) dfs(u,v);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("mirror.inp","r",stdin);
    freopen("mirror.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {cin>>a[i][j];
         if(a[i][j]=='#') b[i][j]=1;
         else b[i][j]=0;
         cx[i][j]=1;}
    for(int i=0;i<=n+1;i++) b[0][i]=1,b[n+1][i]=1;
    for(int i=0;i<=n+1;i++) b[i][0]=1,b[i][n+1]=1;
    dfs(1,1);
    res=(d-4)*9;
    cout<<res;
    return 0;
}
