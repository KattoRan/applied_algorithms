#include<bits/stdc++.h>
using namespace std;
long long m,n,a,b;
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
    freopen("modulo.inp","r",stdin);
    freopen("modulo.out","w",stdout);
    cin>>m>>n;
    if(ucln(m,n)==1) cout<<"1";
    else cout<<"0";
}


