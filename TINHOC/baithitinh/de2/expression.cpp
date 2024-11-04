#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
int n,a[N];
long long t,s,res,du;
int l[1000007];
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("expression.inp","r",stdin);
    freopen("expression.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i],t+=a[i];
    s=t/2;
    for(int i=1; i<=s; i++)
        l[i]=0;
    l[0]=1;
    for(int i=1; i<=n; i++)
        for(int j=s; j>=a[i]; j--)
            if(l[j-a[i]]==1&&l[j]==0) l[j]=1;
    int m=s;
    while(l[m]==0)
        m--;
    du=t-2*m;
    res=(t-du)/2;
    cout<<res*(t-res);
}
