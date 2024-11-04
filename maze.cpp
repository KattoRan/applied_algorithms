#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+7;
typedef pair<int,int> ii;
const int dx[4]= {-1,0,1,0};
const int dy[4]= {0,1,0,-1};

typedef struct {int w,x,y;} iii;

int a[N][N], kt[N][N];
int m,n,r,c;
int resul;
int BFS(int r, int c)
{
    kt[r][c] = 1;
    queue<iii> q;
    q.push({0,r,c});
    while (q.size())
    {
        int u = q.front().x;
        int v = q.front().y;
        int w = q.front().w;
        //cout << u << " " << v << endl;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = u + dx[i];
            int y = v + dy[i];

            if (x > n || x < 1 || y > m || y < 1) return w + 1;
            if (!kt[x][y] && !a[x][y]) q.push({w+1,x,y}), kt[x][y] = 1;
        }
    }
    return -1;
}
int main()
{
    cin >> n >> m >> r >> c;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    cout << BFS(r,c);
    return 0;
}

