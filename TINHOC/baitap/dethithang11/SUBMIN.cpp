#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
const long long oo=1e19+1;
int a[maxn],n;
long long s[maxn],res;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("SUBMIN.INP","r",stdin);
    freopen("SUBMIN.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    s[0]=0;
    res=oo;
    for(int i=1;i<=n;i++)
        if(a[i]<0) {s[i]=s[i-1]+a[i];
                     res=min(res,s[i]);}
    cout<<res;
    return 0;
}
