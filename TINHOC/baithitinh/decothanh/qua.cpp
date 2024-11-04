#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e3+7;
int a[N][N];
int n;
long long res,f[N][N];
template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-')
    {
        c=getchar();
        tam=-1;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen("qua.inp","r",stdin);
    //freopen("qua.out","w",stdout);
    read(n);
    fu(i,1,n)
    fu(j,1,n)
    read(a[i][j]);
    fu(i,1,n) f[i][1]=1;
    fu(j,2,n)
    fu(i,1,n)
    {
        f[i][j]=f[i+1][j]+f[i-1][j];
        if(a[i][j]>a[i][j-1]) f[i][j]+=f[i][j-1];
    }
    fu(i,1,n) res+=f[i][n];
    fu(i,1,n)
    {
        fu(j,1,n) cout<<f[i][j]<<" ";
        cout<<endl;
    }
    cout<<res;
}
