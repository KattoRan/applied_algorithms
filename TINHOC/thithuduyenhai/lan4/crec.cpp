#include<bits/stdc++.h>
using namespace std;
const int maxn=101;
int n,a,x[maxn],y[maxn],d[maxn];
int res,l[maxn][maxn];
int main()
{
    cin>>n>>a;
    for(int i=1;i<=n;i++) cin>>x[i]>>y[i];
    for(int i=1;i<n;i++)
        for(int j=i+1;j<=n;j++)
    {
      if(x[i]<=y[j])
        {
            if(y[i]<=y[j]) if((x[j]-x[i]+1)*(y[j])<=a) l[i][j]=1;
            if(y[i]>=y[j]) if((x[j]-x[i]+1)*(y[i])<=a) l[i][j]=1;
        }
        if(x[i]>=x[j])
        {
            if(y[i]<=y[j]) if((x[i]-x[j]+1)*(y[j])<=a) l[i][j]=1;
            if(y[i]>=y[j]) if((x[i]-x[j]+1)*(y[i])<=a) l[i][j]=1;
        }
        if(l[i][j]==1) d[i]++;
    }
    for(int i=1;i<=n-1;i++) if(d[i]==d[i+1]) res++;
    cout<<res;
}
