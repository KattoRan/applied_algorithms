#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=30007;
int n;
long long a[N],f[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("jump.inp","r",stdin);
    freopen("jump.out","w",stdout);
    cin>>n;
    fu(i,1,n) cin>>a[i];
    f[1]=0;
    f[2]=abs(a[2]-a[1]);
    for(int i=3;i<=n;i++)
        f[i]=min(f[i-1]+abs(a[i]-a[i-1]),f[i-2]+3*abs(a[i]-a[i-2]));
    cout<<f[n];
}

