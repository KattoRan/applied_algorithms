#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
long long a[N],n,res,d;
bool ok(long long a)
{
    int k=sqrt(2*a);
    if(k*(k+1)==2*a)
        return 1;
    return 0;
}
main()
{
    #define name "maxseq"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    res=0;
    for(int i=1; i<=n; i++){
        if(ok(a[i]))
        {
            if(a[i]>=a[i-1]) d++;
            else d=1;
            res=max(res,d);
        }
        else d=0;
    }
    cout<<res;
}
