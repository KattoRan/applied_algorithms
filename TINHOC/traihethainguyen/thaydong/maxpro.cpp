#include<bits/stdc++.h>
using namespace std;
const int maxn=3000;
int n,s,t,res,tich;
int f[300][300];
void cnkl()
{
     if(s==n&&t>res) res=t;
}
void tryy(int i)
{
    for(int j=0;j<=1;j++)
    {
        if (j==1) s+=i,t*=i;
        if(i==n) cnkl();
        else if(s<=n) tryy(i+1);
        if(j==1) s-=i,t/=i;
    }
}

int cal(int s,int mx)
{
    if(f[s][mx]>-1) return f[s][mx];
    if(s==0) return 1;
    if(mx==0) return 0;
    int best =cal(s,mx-1);
    if(s>=mx) best=max(best,cal(s-mx,mx-1)*mx);
    f[s][mx]=best;
    return best;
}
int main()
{
    freopen("maxpro.inp","r",stdin);
    freopen("maxpro.out","w",stdout);
    cin>>n;
    res=0;t=1;s=0;
    if(n<=30) {tryy(1); cout<<res;}
  //  if(n<=300) {f[n+1][n+1]=-1;cout<<cal(n+1,n+1);}

}
