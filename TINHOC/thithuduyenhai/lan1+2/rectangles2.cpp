#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+1;
int x[maxn][maxn];
int n,m,p,res,d;
void khoitao()
{
    cin>>n>>m>>p;
}
void xuly()
{
    x[1][1]=m*n;
    for(int i=2; i<=n; i++)
        x[i][1]=x[i-1][1]-m;
    d=n;
    int j=1;
    while(d!=0)
    {
        for(int i=2; i<=m; i++)
            x[j][i]=x[j][i-1]-d;
        d--;
        j++;
    }
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if((i*2+j*2)>=p)
                res=res+x[i][j];
        }
    cout<<res;
}
int main()
{
    khoitao();
    xuly();
}

