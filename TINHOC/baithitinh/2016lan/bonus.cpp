#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
int n,m;
int a[N];
int f[N];
long long s[N];
long long res;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("bonus.inp","r",stdin);
    freopen("bonus.out","w",stdout);
    cin>>n>>m;
    fu(i,1,n) cin>>a[i];
    int ma=1e6+7;
    int nk=sqrt(ma);
    f[1]=1;
    f[0]=1;
    fu(i,2,nk)
    if(f[i]==0)
        for(int j=i*i;j<=ma;j+=i)
        f[j]=1;
    fu(i,1,n)
    if(f[a[i]]) a[i]=0;
    fu(i,1,n) s[i]=s[i-1]+a[i];
    res=0;
    while(m--)
    {
        int i,j;
        cin>>i>>j;
        res=max(res,s[j]-s[i-1]);
    }
    cout<<res;

}
