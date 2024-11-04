#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int m,n,a[N];
long long res;
template<typename T> inline void read(T& x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c=='-')
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
    #define name "fm"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    read(m);
    for(int i=1;i<=n;i++)
        read(a[i]);
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
        int j=upper_bound(a+i+1,a+n+1,m-a[i])-a;
        res+=(j-i-1);
    }
    cout<<res;
}
