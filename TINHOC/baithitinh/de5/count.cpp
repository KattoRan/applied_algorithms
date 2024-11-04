#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e3+7;
int n;
string s,f[N][N];
long long res;
map<string,int> d;
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("count.inp","r",stdin);
    freopen("count.out","w",stdout);
    cin>>s;
    n=s.size();
    s='+'+s;
    fu(i,1,n)
    fu(j,i,n)
   {
    f[i][j]="";
    fu(k,i,j)
    f[i][j]=f[i][j]+s[k];
   }
   fu(i,1,n)
   fu(j,i,n)
   {
       res++;
       d[f[i][j]]++;
       if(d[f[i][j]]>1) res--;
   }
   cout<<res;
}
