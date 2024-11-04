#include<iostream>
#include<algorithm>
#define mod 10000000007
using namespace std;
int n,m,k;
int f[5005][5005]={};
int calc(int s,int i)
{
    if(f[s][i]!=-1)return f[s][i];
    if(i==n)
    {
        return 1;
    }
    int sum=0;
    if(s-k>0)sum=(sum%mod+calc(s-k,i+1)%mod)%mod;
    if(s+k<m)sum=(sum%mod+calc(s+k,i+1)%mod)%mod;
    return f[s][i]=sum;
}
main()
{

	ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>k>>m>>n;
    int res=0;
    for(int i=1;i<=5000;i++)
        for(int j=1;j<=5000;j++)
    f[i][j]=-1;
    for(int i=1;i<=m-1;i++)
    {
        res=(res+calc(i,1))%mod;
    }
    cout<<res;
}

