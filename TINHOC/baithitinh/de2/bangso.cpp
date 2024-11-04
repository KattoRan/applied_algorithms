#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,a[N];
long long f[N][3],res;
void read(int &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-')
    {
        c=getchar();
        tam=-1;
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}
main()
{
    #define name "bangso"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    for(int i=1;i<=n;i++)
    {
        f[i][1]=max(f[i-1][1],f[i-1][2]+a[i]);
        f[i][2]=max(f[i-1][2],f[i-1][1]-a[i]);
        res=max(f[i][1],f[i][2]);
    }
    cout<<res;
}
