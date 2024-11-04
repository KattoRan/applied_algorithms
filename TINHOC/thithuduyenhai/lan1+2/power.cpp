#include<iostream>
#include<algorithm>
using namespace std;
const int maxn=1e4+1;
int n,k;
int a[maxn],f[maxn],kq[maxn];
long long g[maxn],res;
void ptts(int h)
{
    int d,l[43]= {};
    for(int i=2; i<=43; i++)
        while(h%i==0)
        {
            l[i]++;
            h/=i;
        }
    for(int i=2; i<=43; i++)
        f[i]=max(f[i],l[i]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("power.inp","r",stdin);
    freopen("power.out","w",stdout);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    for(int i=1; i<=n; i++)
        ptts(a[i]);
    for(int i=1; i<=n; i++)
        g[i]=i*k;
    for(int i=1; i<=43; i++)
        if(f[i]!=0)
        {
            int j=lower_bound(g+1,g+n+1,f[i])-g;
            kq[i]=j;
        }
    res=1;
    for(int i=2; i<42; i++)
        if(kq[i]!=0)
        {
            for(int j=1; j<=kq[i]; j++)
                res=res*i;
        }
    cout<<res;
    return 0;
}
