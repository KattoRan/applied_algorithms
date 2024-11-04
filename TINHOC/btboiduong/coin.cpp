#include<bits/stdc++.h>
using namespace std;
const int oo=1e7+7;
const int maxn=1e3+1;
int n;
int l[maxn],f[25][maxn],cs[maxn];
int a[25];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("coin.inp","r",stdin);
    //freopen("coin.out","w",stdout);
    cin>>n;
    for(int i=1; i<=20; i++)
        a[i]=i*i;
    for(int i=0; i<=20; i++)
        f[i][0]=0;
    for(int j=1; j<=n; j++)
        f[0][j]=oo;
    l[0]=1;
    for(int i=1; i<=20; i++)
        for(int j=n; j>=0; j--)
        if(a[i]<=j)
            for(int k=1;k*a[i]<=j;k++)
            l[j]+=l[j-a[i]*k];
    cout<<l[n]<<'\n';
    for(int i=1; i<=20; i++)
        for(int j=1; j<=n; j++)
        {
            if(a[i]>j)
                f[i][j]=f[i-1][j];
            else
                f[i][j]=min(f[i-1][j],1+f[i][j-a[i]]);
        }
    cout<<f[20][n]<<'\n';
    int i,j;
    i=20;j=n;
    while(i>=1&&j>=1)
    {
        if(f[i][j]==f[i-1][j]) cs[i]=0;
        else cs[i]++,j-=a[i];
        i--;
    }
    for(int i=20;i>=1;i--)
        //if(cs[i])
        cout<<cs[i]<<" "<<i<<'\n';
}
