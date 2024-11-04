#include <bits/stdc++.h>
using namespace std;
const int maxn=101;
int n,m,kiluc,gia;
int a[maxn][maxn];
int x[maxn],ts[maxn],sm[maxn],sum[maxn];
void init()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        {cin>>ts[i];
         for(int j=1;j<=ts[i];j++) cin>>a[i][j];}
    kiluc=0;gia=0;
    for(int i=0;i<=31;i++) sm[i]=0;
    sum[m]=ts[m];
    for(int i=m-1;i>=1;i--) sum[i]=sum[i+1]+ts[i];
}
void cnkl()
{
    if(gia>kiluc)
        {kiluc=gia;
         }
}
void thuemay(int i)
{
        for(int j=1;j>=0;j--)
        { x[i]=j;
          if(j==0) {if(i>=m) cnkl();
                    else if(gia+sum[i+1]>kiluc) thuemay(i+1);}
          if(j==1)
          {
           int ok=1;
           for(int k=1;k<=ts[i];k++)
                  if(sm[a[i][k]]+1>n) {ok=0;
                                        break;}
           if(ok)
          {  for(int k=1;k<=ts[i];++k) ++sm[a[i][k]];
             gia+=ts[i];
             if(i>=m) cnkl();
                 else if(gia+sum[i+1]>kiluc) thuemay(i+1);
             for(int k=1;k<=ts[i];++k) --sm[a[i][k]];
             gia-=ts[i];}
          }
        }
}
int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("THUEMAY.inp","r",stdin);
    freopen("THUEMAY.out","w",stdout);
    init();
    thuemay(1);
    cout<<kiluc;
    return 0;
}
