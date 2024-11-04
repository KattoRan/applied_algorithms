#include<bits/stdc++.h>
#define task "mien"
using namespace std;
const int maxn=1e3+7;
const int dy[4]={-1,0,1,0};
const int dx[4]={0,-1,0,1};
int m,n,cx[maxn][maxn],demlt,d;
int a[maxn][maxn];
void DFS(int x,int y)
{
     cx[x][y]=0;
     d++;
     for(int i=0;i<4;i++)
        {
            int u=x+dx[i];
            int v=y+dy[i];
            if(cx[u][v]&&a[x][y]==a[u][v]) DFS(u,v);
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>m>>n;
    for(int i=1; i<=m; i++)
    for(int j=1;j<=n;j++) cin>>a[i][j];
    for(int i=1; i<=m; i++)
    for(int j=1;j<=n;j++)
        cx[i][j]=1;
    demlt=0;
    int r1,r2,r3;
    r1=0;
    for(int i=1; i<=m; i++)
    for(int j=1;j<=n;j++)
        if(cx[i][j])
        {
            demlt++;
            d=0;
            DFS(i,j);
            if(d>r1) {r1=d;r2=i;r3=j;}
        }
    cout<<demlt<<'\n';
    cout<<r1<<" "<<r2<<" "<<r3;
    return 0;
}
