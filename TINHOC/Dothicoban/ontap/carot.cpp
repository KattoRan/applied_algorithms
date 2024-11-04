#include <bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
const int oo=1e8+5;
const int dx[5]= {0,-1,0,1,0};
const int dy[5]= {0,0,1,0,-1};
int m,n,x,y,gia,a[maxn][maxn],kc,res,kq,cx[maxn][maxn];
void dfs(int u,int v)
{
    cx[u][v]=0;
    gia++;
    kc=min(kc,abs(x-u)+abs(y-v));
    for(int i=1; i<=4; i++)
    {
        int t=u+dx[i];
        int s=v+dy[i];
        if(cx[t][s]&&a[t][s]) dfs(t,s);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CAROT.INP","r",stdin);
    freopen("CAROT.OUT","w",stdout);
    cin>>m>>n>>x>>y;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++) cin>>a[i][j],cx[i][j]=1;
    for(int i=1; i<=m; i++)
        for(int j=1; j<=n; j++)
        {
            if(cx[i][j]&&a[i][j])
            {
                gia=0;
                kc=oo;
                dfs(i,j);
                if(gia>res) res=gia,kq=kc;
                else if(gia==res) kq=min(kq,kc);
            }
        }
    cout<<res<<" "<<kq;
}
