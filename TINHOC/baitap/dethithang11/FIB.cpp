#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
int a[maxn],res,dau,cuoi,d,dem,f[maxn],n,x,k[maxn];
long long t;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("FIB.INP","r",stdin);
    freopen("FIB.OUT","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    res=a[1];
    f[0]=0;
    f[1]=1;
    d=1;
    for(int i=2; i<=n; i++)
        res=max(res,a[i]);
    for(int i=2; f[i-1]<=res; i++)
        f[i]=f[i-1]+f[i-2],d++;
    if(f[d]>res)
        d--;
    dau=1;
    cuoi=d;
    for(int i=1; i<=n; i++)
    {
        while(dau<=cuoi)
        {
            x=(dau+cuoi)/2;
            if(a[i]==f[x])
                k[i]=1;
            else
                k[i]=0;
            break;
            if(a[i]<f[x])
                cuoi=x-1;
            if(a[i]>f[x])
                dau=x+1;
        }
    }
    for(int i=1; i<=n; i++)
        if(k[i]==0)
            dem++,t+=a[i];
    cout<<dem<<" "<<t;
    return 0;
}
