#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
int n,k,l[N];
long long t,res,d;
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
bool ok(long long x)
{
    int dem=0;
    for(int i=1;i<=n;i++)
        dem+=l[i]/x;
    return (dem>=k);
}
void solve1()
{
    int l=1;int r=1000000000;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(ok(mid))
        {
            res=mid;
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<res;
}
void solve2()
{

}
main()
{
    #define name "wires"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    read(k);
    fu(i,1,n) read(l[i]);
    solve1();
}
