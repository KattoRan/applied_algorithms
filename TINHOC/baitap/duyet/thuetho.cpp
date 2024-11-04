#include<bits/stdc++.h>
using namespace std;
const int maxn=10e3+1;
int n,x0[maxn],x[maxn];
bool cx[maxn];
int c[maxn][maxn],gia,kiluc,canduoi;
void init()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>c[i][j];
    for(int i=1;i<=n;i++) kiluc+=c[i][i];
    for(int i=1;i<=n;i++) cx[i]=1;
}
void cnkl()
{
    if(gia<kiluc) {kiluc=gia;
                   for(int i=1;i<=n;i++)
                      x0[i]=x[i];
                   }
}
void try1(int i)
{
  for(int j=1;j<=n;j++)
    if(cx[j])
  {
      x[i]=j;
      cx[j]=0;
      gia+=c[i][j];
      if(i==n) cnkl();
      else if(gia<kiluc) try1(i+1);
      gia-=c[i][j];
      cx[j]=1;
  }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("thuetho.inp","r",stdin);
    freopen("thuetho.out","w",stdout);
    init();
    try1(1);
    cout<<kiluc<<'\n';
    for(int i=1;i<=n;i++) cout<<x0[i];
    return 0;
}
