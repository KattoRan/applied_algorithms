#include<bits/stdc++.h>
#define task "cow1"
using namespace std;
const int N=17;
int n,k;
long long a[N],t[N],res;
long long f[N][1<<N];
int getbit(int x,int k)
{
    return (x>>k)&1;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=0;i<n;i++)
        f[i+1][1<<i]=1;
    for(int x=1;x<(1<<n);x++)
    {
        int d=0;
        for(int i=1;i<=n;i++)
            if(getbit(x,i-1)) d++,t[d]=i;
        if(d>1)
        {
            for(int j=1;j<=d;j++)
            {
                int x1=x^(1<<(t[j]-1));
                for(int i=1;i<=d;i++)
                    if(i!=j&&(abs(a[t[i]]-a[t[j]])>k))
                f[t[j]][x]+=f[t[i]][x1];
            }
        }
    }

    for(int i=1;i<=n;i++)
        res+=f[i][(1<<n)-1];
    cout<<res;
}
