#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int n,d[maxn],a[maxn],t,dem;
bool fibonaci(int m)
{
    int f[m];
    f[0]=0;
    f[1]=1;
    int d=1;
    for(int i=2; f[i-1]<=m; i++)
    {
        f[i]=f[i-1]+f[i-2];
        d++;
    }
    for(int i=d; i>=1; i--)
        if(m==f[i])
            return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("FIBONACI.INP","r",stdin);
    freopen("FIBONACI.OUT","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=n; i++)
        if(fibonaci(a[i]))
            d[i]=1;
        else
            d[i]=0;
    dem=0;
    t=0;
    for(int i=1; i<=n; i++)
        if(d[i]==0)
            dem++,t+=a[i];
    cout<<dem<<" "<<t;
    return 0;
}

