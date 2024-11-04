#include<bits/stdc++.h>
using namespace std;
long long n,d,s;
bool nto(long long a)
{
    if(a<2) return false;
    else
        for(int i=2;i<=sqrt(a);i++)
          if(a%i==0) return false;
    return true;
}
int main()
{   ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("PASS.INP","r",stdin);
    freopen("PASS.OUT","w",stdout);
    cin>>n;
    s=0;d=0;
    for(int i=1;i<=n;i++)
       if(n%i==0&&nto(i)) {d++;s+=i;}
    cout<<d<<" "<<s;
    return 0;
}
