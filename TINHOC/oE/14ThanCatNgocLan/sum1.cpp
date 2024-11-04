#include<bits/stdc++.h>
using namespace std;
const int oo=1e9+7;
const int N=127;
int n,a[N],k,gia,kiluc,b[N];
int x[N],x0[N],t;
void nhan()
{
    if(t==k&&gia<kiluc)
    {
        kiluc=gia;
        for(int i=1; i<=n; i++) x0[i]=x[i];
    }
}
void try1(int i)
{
    for(int j=0; j<=1; j++)
    {
        x[i]=j;
        if(j==1) gia++,t+=a[i];
        if(i==n) nhan();
        else
        {
            int maxi;
            maxi=b[i];
            if(t<=k&&gia+(k-t)/maxi<kiluc)
                try1(i+1);
        }
        if(j==1) gia--,t-=a[i];
    }
}
main()
{
    #define name "sum1"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>n>>k;
    for(int i=1; i<=n; i++)cin>>a[i];
    kiluc=n+1;
    gia=0;
    for(int i=1; i<n; i++)
    {
        b[i]=a[i+1];
        for(int j=i+2; j<=n; j++)
            if(a[j]>b[i]) b[i]=a[j];
    }
    try1(1);
    if(kiluc==n+1) cout<<"-1";
    else
    {
        cout<<kiluc<<'\n';
        for(int i=1; i<=n; i++) if(x0[i]) cout<<i<<" ";
    }
}
