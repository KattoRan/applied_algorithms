#include<bits/stdc++.h>
using namespace std;
const int N=3*1e6+7;
int n,m,a[N],b[N];
long long res;
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
    #define name "a1"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++) read(a[i]),read(b[i]);
    sort(b+1,b+n+1);
    for(int i=1;i<=n;i++)
    {
        int j=upper_bound(b+1,b+n+1,a[i])-b;
        res+=(j-1);
    }
    cout<<res;
}

