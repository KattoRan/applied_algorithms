#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int k,n,d1,d2,resm;
int res;
string s;
int main()
{
    cin>>n>>k;
    cin>>s;
    d1=0;
    d2=0;
    res=0;
    resm=0;
    for(int i=0; i<=n-1; i++)
    {
        if(s[i]=='O')
            d1++;
        if(s[i]=='R')
            d2++;
        for(int j=i+1; j<=n-1; j++)
        {
            if(s[j]=='O')
                d1++;
            if(s[j]=='R')
                d2++;
            if(d1==d2*k)
                res=d1+d2;
            if(res>resm)
                resm=res;
        }
        d1=0,d2=0;
    }
    cout<<resm;
    return 0;
}
