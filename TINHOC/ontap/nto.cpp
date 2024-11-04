#include<bits/stdc++.h>
using namespace std;
long long x;
bool kt(long long x)
{
    int n=sqrt(x);
    if(x<2) return 0;
    if(x==2) return 1;
    for(int i=2;i<=n;i++)
    if(x%i==0) return 0;
    return 1;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("nto.inp","r",stdin);
    freopen("nto.out","w",stdout);
    cin>>x;
    if(kt(x)) cout<<"YES";
    else cout<<"NO";
}
