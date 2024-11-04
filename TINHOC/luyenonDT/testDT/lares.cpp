#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define task "lares"
using namespace std;

typedef long long ll;
int n,m,k,res;
void xuli1()
{
    res=0;
    fu(i,0,k)
    {
        int mnp=min((m-i)/2,n+i-k);
        res=max(res,mnp);
    }
    cout<<res;
}

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>m>>n>>k;
    if(k>m+n) return 0;
    else xuli1();
    return 0;
}
