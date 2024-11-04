#include<bits/stdc++.h>
using namespace std;
long long a,b,m;
long long ucln(long long m,long long n)
{
    long long r;
    while (n!=0 )
    {
        r=m%n;
        m=n;
        n=r;
    }
    return m;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("phanso.inp","r",stdin);
    freopen("phanso.out","w",stdout);
    cin>>a>>b;
    m=ucln(a,b);
    cout<<a/m<<" "<<b/m;
}
