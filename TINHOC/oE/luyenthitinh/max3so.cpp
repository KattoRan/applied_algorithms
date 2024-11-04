#include<bits/stdc++.h>
using namespace std;
string a,b,c;
string max3so(string a,string b,string c)
{
    string m;
    if(a.size()>b.size()) m=a;
    else m=b;
    if(a.size()==b.size())
        if(a<b) m=a;
        else m=b;
    if(m.size()>c.size()) return m;
    else return c;
    if(m.size()==c.size())
        if(m<c) return c;
        else return m;
}
main()
{
    #define name "max3so"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>a>>b>>c;
    cout<<max3so(a,b,c);
}
