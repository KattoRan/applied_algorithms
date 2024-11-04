// cat \\

#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
int n,p[N];
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
    #define name "orange"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    fu(i,1,n) read(p[i]);
    sort(p+1,p+n+1);
    res=0;
    fu(i,1,p[n])
    {
        int j=upper_bound(p+i+1,p+n+1,i)-p;
        if(j!=n+1)
            if(p[j-1]==p[i]) res=max(res,(long long)p[i]*(n-j+2));
            else res=max(res,(long long)p[i]*(n-j+1));
    }
    cout<<res;
}
