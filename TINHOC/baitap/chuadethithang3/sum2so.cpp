#include<bits/stdc++.h>
using namespace std;
string a,b;
string add(string a,string b)
{
    string res;
    int t,nho;
    while(a.size()<b.size()) a="0"+a;
    while(b.size()<a.size()) b="0"+b;
    res="";nho=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        t=a[i]+b[i]-96+nho;
        nho=t/10;
        t=t%10;
        res=char(t+48)+res;
    }
    if(nho>0) res="1"+res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sum2so.INP","r",stdin);
    freopen("sum2so.OUT","w",stdout);
    cin>>a>>b;
    cout<<add(a,b);
    return 0;
}
