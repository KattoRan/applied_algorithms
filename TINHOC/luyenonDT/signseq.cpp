#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i++)
using namespace std;
const int N=1e4+7;
int n,l,u,a[N];
int f1[N],f2[N],res;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("signseq.inp","r",stdin);
    freopen("signseq.out","w",stdout);
    cin>>n>>l>>u;
    fu(i,1,n) cin>>a[i];
    fu(i,1,n)
    f1[i]=1,f2[i]=1;
    fu(j,1,n)
    {
        fu(i,1,j-l)
        {
            if(a[j]>a[i]&&a[j]-a[i]>=u) f1[j]=max(f1[j],f2[i]+1);
            if(a[i]>a[j]&&a[i]-a[j]>=u) f2[j]=max(f2[j],f1[i]+1);
        }
    }
    fu(i,1,n)
    res=max(max(res,f1[i]),f2[i]);
    cout<<res;
}
