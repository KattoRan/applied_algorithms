#include<bits/stdc++.h>
#define fort(i,a,b) for(int i=a;i<=b;i++)
#define foru(i,a,b) for(i=a;i>=b;i--)
using namespace std;
const int maxn=1e3+7;
typedef pair<int, int> ii;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int n,m;
vector <ii> ke[maxn][maxn];
int kq=0;
int cx[maxn][maxn];
int sang[maxn][maxn];

void BFS(int sx, int sy)
{
 queue<ii>q;
 q.push(make_pair(sx,sy));
  cx[sx][sy]=1;
  sang[sx][sy] = 1;

  while(!q.empty())
  {
    ii ve = q.front();
    int u = ve.first;
    int v = ve.second;

    q.pop();


    for (int i = 0; i < 4; ++i)
        {
      int uu = u + dx[i];
      int vv = v + dy[i];
      if (sang[uu][vv] == 1 && cx[uu][vv] == 0)
       {
        q.push(ii(uu,vv));
        cx[uu][vv] = 1;
      }
    }

    for (int i = 0; i < ke[u][v].size(); ++i) {
      int uu = ke[u][v][i].first;
      int vv = ke[u][v][i].second;
      if(sang[uu][vv]==0)
      { sang[uu][vv] = 1;
      kq++;
      }

      for (int j = 0; j < 4; ++j) {
        int uuu = uu + dx[j];
        int vvv = vv + dy[j];

        if (cx[uuu][vvv] == 1 && cx[uu][vv] == 0) {
          q.push(ii(uu,vv));
          cx[uu][vv] = 1;
        }
      }
    }

  }
}
int main()
{
    freopen("SWICTH.inp","r",stdin);
    freopen("SWICTH.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   cin>>n>>m;
  fort(i,1,m)
  {
    int x,y,z,b;
    cin>>x>>y>>z>>b;
    ke[x][y].push_back(ii(z,b));
  }
  fort(i,1,n)
    fort(j,1,n)
    cx[i][j]=0;
    kq = 1;
  BFS(1,1);
  cout<<kq;
  return 0;
}
