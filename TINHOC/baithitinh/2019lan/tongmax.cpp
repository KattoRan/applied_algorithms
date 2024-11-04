#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
const int oo=1e9+7;
long long n,a[N],res,tong;
main()
{
    #define name "tongmax"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen(name".inp","r",stdin);
	//freopen(name".out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    res=-oo;
    for(int i=1;i<=n;i++)
    {
        tong+=a[i];
        res=max(res,tong);
        if(tong<0) tong=0;
    }
    cout<<res;
}
