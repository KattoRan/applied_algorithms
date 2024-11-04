#include<bits/stdc++.h>
#define oo 10000007
#define f first
#define s second
using namespace std;
int dx[5]= {0,-1,0,1,0};
int dy[5]= {0,0,-1,0,1};
vector<pair<long long,long long> >ban,bi;
pair<long long,long long>ho;
vector<long long>duongdi;
long long xmax,ymax,xmin,ymin,n,m,dem,a[1000][1000],d;
long long res;
void dfs(long long x,long long y)
{
    if(a[x][y]==2)d=min(d,dem);
    else
    {
        dem++;
        a[x][y]=1;
        if(dem<d)
        {
            for(int i=1; i<=4; i++)
            {
                long long u=x+dx[i];
                long  long v=y+dy[i];
                if(a[u][v]!=-1&&a[u][v]!=1&&u>=xmin&&u<=xmax&&y>=ymin&&y<=ymax)
                {
                    dfs(u,v);
                }
            }
        }
        a[x][y]=0;
        dem--;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ballgame.inp","r",stdin);
    freopen("ballgame.out","w",stdout);
    cin>>n;
    xmax=ymax=-oo;
    ymin=xmin=oo;
    long long x=0,y=0;
    for(int i=1; i<=n; i++)
    {
        long long u,v;
        cin>>u>>v;
        xmax=max(xmax,u);
        xmin=min(xmin,u);
        ymax=max(ymax,v);
        ymin=min(ymin,v);
        a[u][v]=-1;
        ban.push_back({u,v});
    }
    cin>>m;
    for(int i=1; i<=m; i++)
    {
        long long u,v;
        cin>>u>>v;
        xmax=max(xmax,u);
        xmin=min(xmin,u);
        ymax=max(ymax,v);
        ymin=min(ymin,v);
        x=x+u;
        y=y+v;
        bi.push_back({u,v});
    }
    bool dddq=0;
    if(n==1&&m==2)
    {
        if(bi[0].f==bi[1].f&&bi[0].f==ban[0].f)dddq=1;
        if(bi[0].s==bi[1].s&&bi[0].s==ban[0].s)dddq=1;
    }
    if(n<=1&&m==2)
    {
        res=abs(bi[0].f-bi[1].f)+abs(bi[0].s-bi[1].s);
        if(!dddq)cout<<res;
        else cout<<res+2;
    }
    else
    {
        ho= {x/m,y/m};
        if(n==0)
        {
            for(int i=0; i<=m-1; i++)
            {
                duongdi.push_back(abs(bi[i].f-ho.f)+abs(bi[i].s-ho.s));
            }
        }
        else
        {
            xmax++;
            ymax++;
            xmin--;
            ymin--;
            if(a[ho.f][ho.s]==-1)
            {
                for(int i=1; i<=4; i++)
                {
                    if(a[ho.f+dx[i]][ho.s+dy[i]]!=-1)
                    {
                        ho.f=ho.f+dx[i];
                        ho.s=ho.s+dy[i];
                        break;
                    }
                }
            }
            a[ho.f][ho.s]=2;
            long long hhh=bi.size();
            for(int i=0; i<=hhh-1; i++)
            {
                d=oo;
                dem=0;
                dfs(bi[i].f,bi[i].s);
                duongdi.push_back(d);
            }
        }
        for(auto i:duongdi)res+=i;
        cout<<res;
    }
}
/*
3
2 1
2 2
2 0
3
3 2
1 1
3 1
*/

