#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int n;
string a[maxn];
vector<string>  res;
int main()
{
   freopen("maxv.inp","r",stdin);
   freopen("maxv.out","w",stdout);
   cin>>n;
   for(int i=1;i<=n;i++) cin>>a[i];
   for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
   {
       if(a[i]+a[j]<a[j]+a[i])
       {
           swap(a[i],a[j]);
       }
   }
   for(int i=1;i<=n;i++) cout<<a[i];

}
