#include<bits/stdc++.h>
using namespace std;
const int oo=1e9+7;
const int maxn=125;
int n,a[maxn],k,gia,kiluc;
int x[maxn],x0[maxn],t;
void init()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     freopen("sum2.inp","r",stdin);
     freopen("sum2.out","w",stdout);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    kiluc=0;
    gia=0;
}
void ghinhan()
{
       if(t==k&&gia>kiluc) {kiluc=gia;
                            for(int i=1;i<=n;i++) x0[i]=x[i];}
}
void try1(int i)
{
    for(int j=1;j>=0;j--)
    {
        x[i]=j;
        if(j==1) gia++,t+=a[i];
        if(i==n) ghinhan();
        else { int mini;
               mini=a[i+1];
               for(int k=i+2;k<=n;k++)if(a[k]>mini) mini=a[k];
               if(t<=k&&gia+(k-t)/mini>kiluc) try1(i+1);}
        if(j==1) gia--,t-=a[i];
    }
}
int main()
{
    init();
    try1(1);
    if(kiluc==0) cout<<"-1";
    else {cout<<kiluc<<'\n';
          for(int i=1;i<=n;i++) if(x0[i]!=0) cout<<i<<" ";}
    return 0;
}
