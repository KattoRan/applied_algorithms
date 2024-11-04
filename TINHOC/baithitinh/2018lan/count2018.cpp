#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e5+7;
int n,k,res;
int a[N];
long long s[N];
map<long long,int> m;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("count.inp","r",stdin);
    freopen("count.out","w",stdout);
    cin>>n>>k;
    fu(i,1,n) cin>>a[i];
    fu(i,1,n) s[i]=s[i-1]+a[i];
    res=0;
    fu(i,4,n)
    {
        m[s[i-4]]++;
        res+=m[s[i]-k];
    }
    cout<<res;
}
