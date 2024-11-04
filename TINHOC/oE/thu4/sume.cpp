#include<bits/stdc++.h>
using namespace std;
string a,b;
int res;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sume.inp","r",stdin);
    freopen("sume.out","w",stdout);
    cin>>a>>b;
    int n=a.size();
    int m=b.size();
    int k=__gcd(m,n);
    for(int i=1;i<=k;i++)
    if(n%i==0&&m%i==0)
    {
        string s1=a.substr(0,i);
        string s2=b.substr(0,i);
        if(s1!=s2) continue;
        string x1="";
        string x2="";
        int k1=n/i;
        for(int j=1;j<=k1;j++) x1+=s1;
        if(x1!=a) continue;
        k1=m/i;
        for(int j=1;j<=k1;j++) x2+=s2;
        if(x2!=b) continue;
        res++;
    }
    cout<<res;
}
