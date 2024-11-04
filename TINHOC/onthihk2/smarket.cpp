#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define mod 131131
using namespace std;
const int N=507;
const int S=1e4+7;
int n,s,c[N],m[N];
int f[N][S];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   /* freopen("smarket.inp","r",stdin);
    freopen("smarket.out","w",stdout);*/
    cin>>s>>n;
    fu(i,1,n) cin>>c[i]>>m[i];
    fu(i,0,n) f[i][0]=1;
    fu(i,1,n)
    fu(j,0,s)
    {
        if(c[i]>j) f[i][j]=f[i-1][j];
        else
        {
            fu(k,0,m[i])
            if(k*c[i]<=j) f[i][j]=(f[i-1][j-k*c[i]]%mod+f[i-1][j]%mod)%mod;
        }
    }
    cout<<f[n][s];
}
