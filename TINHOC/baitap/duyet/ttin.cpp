#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
const int oo=1e9+1;
long x[maxn],x0[maxn],t;
long m,gia,n,s[maxn][maxn],kiluc;
void khoitao()
{
    cin>>n>>m;kiluc=oo;
    for(int i=1;i<=m;i++)
       for(int j=1;j<=n;j++) cin>>s[i][j];
}
void cnkl()
{
        if ((t==n)&&(gia<kiluc)) kiluc=gia;
}
void ttin(int i)
{
   for(int j=0;j<=n-t;j++)
     { x[i]=j;
       t=t+j;
       if(j!=0) gia=gia+s[i][j];
       if(i==m) cnkl();
       else if(gia<=kiluc) ttin(i+1);
       if(j!=0) gia=gia-s[i][j];
       t=t-j;}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("ttin.INP","r",stdin);
    freopen("ttin.OUT","w",stdout);
    khoitao();
    ttin(1);
    cout<<kiluc;
    return 0;
}

