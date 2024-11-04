#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
string min2so(string x, string y)
{
    while(x.size()<y.size()) x="0"+x;
    while(y.size()<x.size()) y="0"+y;
    if(x<y) return x;
    else return y;
}
string min3so(string x,string y,string z)
{
    string k=min2so(x,y);
    while(k.size()<z.size()) k="0"+k;
    while(z.size()<k.size()) z="0"+z;
    if(k<z) return k;
    else return z;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("min3so.INP","r",stdin);
    freopen("min3so.OUT","w",stdout);
    cin>>a>>b>>c;
    d=min3so(a,b,c);
    while(d.size()>1&&d[0]=='0') d.erase(0,1);
    cout<<d;
    return 0;
}

