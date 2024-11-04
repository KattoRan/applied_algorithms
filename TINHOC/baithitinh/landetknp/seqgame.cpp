#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
const int oo=3e9+7;
int a[N],b[N];
int n,res;
main()
{
    #define name "seqgame"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>n;
    fu(i,1,n) cin>>a[i];
    fu(i,1,n) cin>>b[i];
    sort(b+1,b+n+1);
    res=oo;
    for(int i=1;i<=n;i++)
    {
        int j=lower_bound(b+1,b+n+1,-a[i])-b;
        int j2=max(j-1,1);
        res=min(res,abs(a[i]+b[j]));
        res=min(res,abs(a[i]+b[j2]));
    }
    cout<<res;

}
