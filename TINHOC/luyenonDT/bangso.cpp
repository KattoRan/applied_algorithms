#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define task "bangso"
using namespace std;
const int N=1e6+7;
typedef long long ll;
int n,a[N];
ll res,m1,m2,m3;

main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    fu(i,1,n) cin>>a[i];
    fu(i,1,n)
    {
        m3=m1;
        if(m1<m2+a[i])m1=m2+a[i];
        if(m2<m3-a[i])m2=m3-a[i];
    }
    res=max(res,max(m1,m2));
    cout<<res;
}
