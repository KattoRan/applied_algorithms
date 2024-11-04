#include<bits/stdc++.h>
using namespace std;
const int oo=1e9+7;
const int maxn=25;
int n,c[maxn][maxn],res,kiluc,minj;
int x[maxn],x0[maxn];
bool cx[maxn];
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("tho.inp","r",stdin);
    freopen("tho.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++) cin>>c[i][j];
    for(int i=1; i<=n; i++) cx[i]=1;
    kiluc=oo;
    minj=oo;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
                 if(c[i][j]<minj) minj=c[i][j];
}
void ghinhan()
{
    if(res<kiluc)
    {
        kiluc=res;
        for(int i=1; i<=n; i++) x0[i]=x[i];
    }
}
void Try(int i)
{
    for(int j=1; j<=n; j++)
        if(cx[j])
        {
            x[i]=j;
            cx[j]=0;
            res+=c[i][j];
            if(i==n) ghinhan();
            else
                if(res+minj*(n-i)<kiluc) Try(i+1);
            res-=c[i][j];
            cx[j]=1;
        }
}
int main()
{
    init();
    Try(1);
    cout<<kiluc<<'\n';
    for(int i=1; i<=n; i++) cout<<x0[i]<<" ";
}
