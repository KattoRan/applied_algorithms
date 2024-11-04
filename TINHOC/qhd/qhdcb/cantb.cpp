#include<bits/stdc++.h>
using namespace std;
const int maxn=31;
long x[maxn],x0[maxn];
long t1,t2,gia,n,p,a[maxn],kiluc;
void khoitao()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>p;
    kiluc=n+1;t1=p;t2=0;gia=0;
}
void cnkl()
{
        if(t1==t2&&gia<kiluc) kiluc=gia;

}
void can(long i)
{
    for(int j=0;j<=2;j++)
    {   x[i]=j;
        if(j!=0) gia++;
        if(j==1) t1+=a[i];
        if(j==2) t2+=a[i];
        if(i==n) cnkl();
        else if(gia<kiluc) can(i+1);
        if(j==2) t2-=a[i];
        if(j==1) t1-=a[i];
        if(j!=0) gia--;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CANTB.INP","r",stdin);
    freopen("CANTB.OUT","w",stdout);
    khoitao();
    can(1);
    if(kiluc==n+1) cout<<"-1";
    else cout<<kiluc;
    return 0;
}
