#include<bits/stdc++.h>
using namespace std;
int k,x,y,d,n;
int a[2050][2050];
void lat(int n,int xt,int yt,int xb,int yb)
{
    int xb1,xb2,xb3,xb4,yb1,yb2,yb3,yb4,xt1,xt2,xt3,xt4,yt1,yt2,yt3,yt4;
    if(n==1) return ;
    d++;
    if(xb<=xt&&yb<=yt)
    {
        a[xt][yt+1]=d;
        a[xt+1][yt+1]=d;
        a[xt+1][yt]=d;
        xb1=xb,yb1=yb;
        xb2=xt,yb2=yt+1;
        xb3=xt+1,yb3=yt+1;
        xb4=xt+1,yb4=yt;
    }
    if(xb<=xt&&yb>yt)
    {
        a[xt][yt]=d;
        a[xt+1][yt+1]=d;
        a[xt+1][yt]=d;
        xb1=xt,yb1=yt;
        xb2=xb,yb2=yb;
        xb3=xt+1,yb3=yt+1;
        xb4=xt+1,yb4=yt;
    }
    if(xb>xt&&yb>yt)
    {
        a[xt][yt]=d;
        a[xt][yt+1]=d;
        a[xt+1][yt]=d;
        xb1=xt,yb1=yt;
        xb2=xt,yb2=yt+1;
        xb3=xb,yb3=yb;
        xb4=xt+1,yb4=yt;
    }
    if(xb>xt&&yb<=yt)
    {
        a[xt][yt]=d;
        a[xt][yt+1]=d;
        a[xt+1][yt+1]=d;
        xb1=xt,yb1=yt;
        xb2=xt,yb2=yt+1;
        xb3=xt+1,yb3=yt+1;
        xb4=xb,yb4=yb;
    }
    xt1=xt-(n/4),yt1=yt-(n/4);
    xt2=xt1,yt2=yt+(n/4);
    xt3=xt+(n/4),yt3=yt2;
    xt4=xt3,yt4=yt1;
    lat(n/2,xt1,yt1,xb1,yb1);
    lat(n/2,xt2,yt2,xb2,yb2);
    lat(n/2,xt3,yt3,xb3,yb3);
    lat(n/2,xt4,yt4,xb4,yb4);
}
int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("latsan.INP","r",stdin);
    freopen("latsan.OUT","w",stdout);
    cin>>k>>x>>y;
    n=1<<k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) a[i][j]=0;
    d=0;
    lat(n,n/2,n/2,x,y);
    for(int i=1;i<=n;i++)
        {for(int j=1;j<=n;j++) cout<<a[i][j]<<" ";
         cout<<'\n';}
    return 0;
}
