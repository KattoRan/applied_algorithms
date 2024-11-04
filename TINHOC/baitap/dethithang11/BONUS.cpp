#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+1;
const int oo=1e19+1;
long long n,a[maxn][maxn];
long long s[maxn][maxn],res;
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
    read(n);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) read(a[i][j]);
    res=-oo;
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++) {s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
                              res=max(res,s[i][j]);}
    cout<<res;
    return 0;
}
