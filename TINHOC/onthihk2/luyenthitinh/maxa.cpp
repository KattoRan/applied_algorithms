#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
const int oo=1e9+18;
int n,a[N],res;
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
    #define name "maxa"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    res=-oo;
    for(int i=1;i<=n;i++)
    {
        read(a[i]);
        if(a[i]<0) res=max(res,a[i]);
    }
    cout<<res;
}

