#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,k,gia,kiluc,t=0,a[N],x[N],x1[N];
void cnkl()
{
    if(t==k&&gia<kiluc) {kiluc=gia;
    for(int i=1;i<=n;i++) x1[i]=x[i];}
}
void tryi(int i)
{
    for(int j=1;j>=0;j--)
    {
        x[i]=j;
        if(j!=0) gia++;
        if(j==1) t+=a[i];
        if(i==n) cnkl();
        else  tryi(i+1);
        if(j==1) t-=a[i];
        if(j!=0) gia--;
    }
}
main()
{
     #define name "sum1"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    kiluc=n+1;
    tryi(1);
    if(kiluc!=n+1)cout<<kiluc<<endl;
    else cout<<"-1";
    for(int i=1;i<=n;i++)
        if(x1[i]==1) cout<<i<<" ";
}
