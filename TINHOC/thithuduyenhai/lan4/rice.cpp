#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+7;
int m,n,k;
int a[maxn],f[maxn],minf[maxn];
int main()
{
    cin>>m>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    minf[0]=-a[1];
    for(int i=1;i<=n;i++)
    {
        int j=lower_bound(a+1,a+n+1,a[i]-k+1)-a-1;
        f[i]=f[j]+k;
        if(j)
        {
            f[i]=min(f[i],minf[j-1]+a[i]+1);
        }
        minf[i]=min(minf[i-1],f[i]-a[i+1]);
    }
    cout<<f[n];
}
