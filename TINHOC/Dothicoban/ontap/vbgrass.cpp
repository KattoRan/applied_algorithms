#include<bits/stdc++.h>
using namespace std;

const int N=107;
const int dx[5]={0,0,-1,0,1};
const int dy[5]={0,-1,0,1,0};

int n,d,cx[N][N],m;
char a[N][N];
long long res;

void dfs(int x,int y)
{
    cx[x][y]=0;
    for(int i=1;i<=4;i++)
    {
        int u=x+dx[i];
        int v=y+dy[i];
        if(a[u][v]=='#'&&cx[u][v]) dfs(u,v);
    }
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {cin>>a[i][j];
         cx[i][j]=1;}
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(a[i][j]=='#'&&cx[i][j]) d++,dfs(i,j);
    }
    cout<<d;
    return 0;
}

