#include <bits/stdc++.h>
using namespace std;
const int maxn=1001;
int n,kiluc,gia;
int a[maxn],s,t,k;
int x[maxn],cs[maxn],x0[maxn];
void cnkl()
{
    if(gia>kiluc&&t%k==0)
        {kiluc=gia;
         for(int i=1;i<=n;i++) x0[i]=x[i];}
}
void daycon(int i)
{
    for(int j=1;j>=0;j--)
        { x[i]=j;
          if(j!=0) gia++;
          if(j==1) t=t+a[i];
          if(i==n) cnkl();
          else if(gia+n-i>kiluc)daycon(i+1);
          if(j==1) t=t-a[i];
          if(j!=0) gia--;
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DAYCON.inp","r",stdin);
    freopen("DAYCON.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin >> a[i];
    for(int i=1;i<=n;i++) cs[i]=i;
    daycon(1);
    cout<<kiluc<<endl;
    for(int i=1;i<=n;i++) if(x0[i]!=0) cout<<cs[i]<<" ";
    return 0;
}
