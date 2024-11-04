#include<bits/stdc++.h>
#define fort(i,a,b) for(int i=a;i<=b;i++)
#define foru(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int maxn = 1e6+7;
int a[maxn];
int n,s,dx[maxn],d;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("skytram.inp","r",stdin);
    freopen("skytram.out","w",stdout);
    cin>>n>>s;
    fort(i,1,n) cin>>a[i];
    sort(a+1,a+n+1);
    fort(i,1,n)
    if(dx[i]==0)
    {   dx[i]=1;
        d++;
        int j=lower_bound(a+i+1,a+1+n,s-a[i]) -a;
        foru(k,j,i)
        if(dx[k]==0 && a[i]+a[k]<=s) {dx[k]=1;break;}
    }
    cout<<d;
    return 0;
}
