// cat \\

#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
#define fi first
#define se second
int n,w;
int a[N],b[N];
pair<int,int> d[N];
void sub1()
{
   int k=0;
   fu(i,1,n)
   {
       cin>>a[i]>>b[i];
       if(a[i]>b[i])
       {
           k++;
           d[k].fi=a[i];
           d[k].se=b[i];
       }
   }

}
main()
{
    cin>>n>>w;
}
