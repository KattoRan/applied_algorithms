#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
int n,sum,res;
int a[N];
long long tong,d,s[N];
int main()
{
     #define name "longest"
     ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 freopen(name".inp","r",stdin);
     freopen(name".out","w",stdout);
     cin>>n>>sum;
     for(int i=1;i<=n;i++) cin>>a[i],s[i]=s[i-1]+a[i];
     res=0;
     if(n<=1000){
     for(int j=1;j<=n;j++)
        for(int i=1;i<=j;i++)
        if(s[j]-s[i-1]<=sum) res=max(res,j-i+1);}
     else{
     for(int i=1;i<=n;i++)
     {

         int j=lower_bound(s+1,s+i-1,-sum+s[i])-s;
         res=max(res,i-j);
     }
     }
     cout<<res;
}
