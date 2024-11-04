#include<bits/stdc++.h>
using namespace std;
string a,b,c;
string max2so(string x, string y)
{
    while(x.size()<y.size()) x="0"+x;
    while(y.size()<x.size()) y="0"+y;
    if(x<y) return y;
    else return x;
}
string max3so(string x,string y,string z)
{
    string k=max2so(x,y);
    while(k.size()<z.size()) k="0"+k;
    while(z.size()<k.size()) z="0"+z;
    if(k<z) return z;
    else return k;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("max3so.INP","r",stdin);
    freopen("max3so.OUT","w",stdout);
    cin>>a>>b>>c;
    cout<<max3so(a,b,c);
    return 0;
}
