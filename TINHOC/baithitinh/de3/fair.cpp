#include <bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define ll long long
using namespace std;
const int N=1e3+7;
const int oo=1e9+7;
const int dx[5]= {0,0,-1,0,1};
const int dy[5]= {0,-1,0,1,0};
typedef pair <int,int> ii;
typedef pair <int,ii> ii1;
int n,m,a[N][N],d[N][N],res;
template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-')
    {
        c=getchar();
        tam=-1;
    }
    while(isdigit(c))
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}

void dij()
{

    priority_queue <ii1,vector <ii1>, greater <ii1> > q;
    fu(i,1,m)
    fu(j,1,n)d[i][j]=oo;
    fu(i,1,m)
    {
        d[i][1]=1;
        q.push(ii1(1,ii(i,1)));
    }
    while(!q.empty())
    {
        int x=q.top().se.fi;
        int y=q.top().se.se;
        int du=q.top().fi;
        q.pop();
        if(d[x][y]!=du)continue;
        fu(i,1,4)
        {
            int x1=x+dx[i];
            int y1=y+dy[i];
            if(x1>=1&&x1<=m&&y1<=n&&y1>=1)
            {
                if(d[x1][y1]>d[x][y]+(a[x1][y1]!=a[x][y]))
                {
                    d[x1][y1]=d[x][y]+(a[x1][y1]!=a[x][y]);
                    q.push(ii1(d[x1][y1],ii(x1,y1)));
                }
            }
        }
    }
}

int main()
{
    #define name "fair"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(m);
    read(n);
    fu(i,1,m)
    fu(j,1,n)
    read(a[i][j]);
    dij();
    int res=oo;
    fu(i,1,m)
    res=min(res,d[i][n]);
    cout<<res;
    return 0;
}

