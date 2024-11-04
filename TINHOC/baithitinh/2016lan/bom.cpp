#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=5*1e6+7;
long long n,s;
long long a[N],l[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("bom.inp","r",stdin);
    freopen("bom.out","w",stdout);
    cin>>n>>s;
    fu(i,1,n) cin>>a[i];
    l[0]=1;
    fu(i,1,n)
    for(int j=s;j>=0;j--)
        if(a[i]+j<=s) l[j+a[i]]+=l[j];
    for(int j=s;j>=0;j--)
    {
        if(l[j]&&j!=0) {cout<<j<<'\n'<<l[j];break;}
        if(j==0) cout<<"0";
    }

}
