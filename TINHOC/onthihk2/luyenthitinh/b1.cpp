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
    #define name "b1"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(m);
    read(n);
    for(int i=1;i<=m;i++) read(a[i]);
    for(int i=1;i<=n;i++) read(b[i]);
    sort(a+1,a+m+1);
    for(int i=1;i<=n;i++)
    {
        int j=upper_bound(a+1,a+m+1,b[i])-a;
        res+=j-1;
    }
    cout<<res;
}

