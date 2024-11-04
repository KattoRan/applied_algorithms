#include<bits/stdc++.h>
#define task "select"
using namespace std;
const int N=1e4+7;
int n,res;
int a[N][8],f[N][1<<8];
bool okk=0;
int getbit(int x,int k)
{
    return (x>>k)&1;
}
int ok(int x)
{
    for(int i=1;i<=3;i++)
        if(getbit(x,i)&getbit(x,i-1)) return 0;
    return 1;
}
int ok1(int x,int y)
{
    for(int i=0;i<=3;i++)
        if(getbit(x,i)&getbit(y,i)) return 0;
    return 1;
}
long long sum(int x,int i)
{
    long long T=0;
    for(int k=0;k<=3;k++)
    if(getbit(x,k)) T=T+a[k+1][i];
    return T;
}
void xuli()
{
    for(int i=1;i<=n;i++)
        for(int x=0;x<16;x++)
        if(ok(x))
    {
        int mn=-1e9+7;
        for(int y=0;y<16;y++)
            if(ok(y)&&ok1(x,y))
            if(mn<f[i-1][y]) mn=f[i-1][y];
        f[i][x]=mn+sum(x,i);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    for(int i=1;i<=4;i++)
        for(int j=1;j<=n;j++) {cin>>a[i][j];if(a[i][j]>0) okk=1;}
    res=-1e9+7;
    if(okk){
    xuli();
    for(int x=0;x<16;x++)
        res=max(res,f[n][x]);
    cout<<res;}
    else
    {
        for(int i=1;i<=4;i++)
        for(int j=1;j<=n;j++)
            res=max(res,a[i][j]);
        cout<<res;
    }
}
