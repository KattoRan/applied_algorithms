#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
const int oo=1e9+7;
int a[N],n;
int sum,res;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subseq.inp","r",stdin);
    freopen("subseq.out","w",stdout);
    cin>>n;
    fu(i,1,n) cin>>a[i];
    res=-oo;
    fu(i,1,n)
    {
        sum+=a[i];
        res=max(res,sum);
        if(sum<0) sum=0;
    }
    cout<<res;
    return 0;
}

