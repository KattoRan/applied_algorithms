#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
const double esp=1e-10;
double x[N];
int n,res,cs1,cs2;
main()
{
    #define name "chiadeu"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(name".inp","r",stdin);
	freopen(name".out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>x[i];
    sort(x+1,x+n+1);
    res=0;
    for(int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n;j++)
    {
        double tmp=(x[i]+x[j])/2;
        cs1=lower_bound(x+1,x+n+1,tmp-esp)-x;
        cs2=upper_bound(x+1,x+n+1,tmp+esp)-x;
        res+=cs2-cs1;
    }
    cout<<res;
}
