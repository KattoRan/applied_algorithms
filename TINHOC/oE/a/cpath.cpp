#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e3+7;
const int mod=1e9+7;
int n,m;
char a[N][N];
long long f[N][N];
template <typename T> inline void read(T& x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-')
        c=getchar();
    if(c=='-')
    {
        tam=-1;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}
main()
{
    #define name "cpath"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>m>>n;
    fu(i,1,m)
    fu(j,1,n) cin>>a[i][j];
    fu(i,1,m)
    fu(j,1,n)
    {
        if(i==1&&j==1) f[i][j]=1;
        else{
        if(a[i][j]=='#')
            f[i][j]=0;
        else
            f[i][j]=(f[i][j-1]%mod+f[i-1][j]%mod)%mod;}
    }
    cout<<f[m][n];

}
