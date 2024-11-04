#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
const int oo=1e9+7;
int n,a[N],b[N],p;
int res;
int tknp(int i,int j)
{
    int d=i,c=j-1,x=j,m;
    while(d<=c)
    {
        m=(d+c)/2;
        if(b[m]>a[j]-p) d=m+1;
        else x=m,c=m-1;
    }
    return x;
}
main()
{
    #define name "jump"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>n>>p;
    fu(i,1,n) cin>>a[i];
    b[1]=a[1];
    fu(i,2,n)
    b[i]=min(a[i],b[i-1]);
    res=0;
    for(int j=2;j<=n;j++)
    {
        int i=tknp(1,j);
        res=max(res,j-i);
    }
    cout<<res;
}
