#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
struct bd
{
    int a,b,k;
    char c;
};
string x,y;
int f[maxn][maxn],m,n;
vector <bd> kq;
vector <bd>::reverse_iterator rit;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("changest.INP","r",stdin);
    //freopen("changest.OUT","w",stdout);
    cin>>x>>y;
    n=x.size();
    m=y.size();
    x="="+x;
    y="="+y;
    for(int j=1; j<=m; j++)
        f[0][j]=j;
    for(int i=1; i<=n; i++)
        f[i][0]=i;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(x[i]==y[j])
                f[i][j]=f[i-1][j-1];
            else
            {
                int d=min(f[i-1][j]+1,f[i][j-1]+1);
                f[i][j]=min(d,f[i-1][j-1]+1);
            }
        }
    cout<<f[n][m]<<endl;
    /*int u,v,sl;
    sl=0;
    u=n;
    v=m;
    bd t;
    while(sl<f[n][m])
    {
        if(x[u]==y[v])
            u--,v--;
        else
        {
            sl++;
            if(u>=1&&f[u][v]==f[u-1][v]+1)
            {
                t.a=u;
                t.b=v;
                t.c=x[u];
                t.k=2;
                u--;
                kq.push_back(t);
            }
            else if(v>=1&&f[u][v]==f[u][v-1]+1)
            {
                t.a=u;
                t.b=v;
                t.c=y[v];
                t.k=1;
                v--;
                kq.push_back(t);
            }
            else
            {
                t.a=u;
                t.b=v;
                t.c=y[v];
                t.k=3;
                u--;
                v--;
                kq.push_back(t);
            }
        }
    }
    for(rit=kq.rbegin(); rit!=kq.rend(); rit++)
    {
        bd t=*rit;
        if(t.k==1)
        {
            cout<<"I"<<" "<<t.b<<" "<<t.c<<endl;
        }
        if(t.k==2)
        {
            cout<<"D"<<" "<<t.b+1<<endl;
        }
        if(t.k==3)
        {
            cout<<"R"<<" "<<t.b<<" "<<t.c<<endl;
        }
    }*/
    return 0;
}

