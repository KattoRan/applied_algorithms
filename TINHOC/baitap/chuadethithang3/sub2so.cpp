#include<bits/stdc++.h>
using namespace std;
string a,b;
int neg;
string sub(string a,string b)
{
    string res;
    int t,nho;
    while(a.size()<b.size()) a="0"+a;
    while(b.size()<a.size()) b="0"+b;
    if(a<b) {swap(a,b);neg=1;}
    res="";nho=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        t=a[i]-b[i]-nho;
        if(t<0) {t=t+10;nho=1;}
        else nho=0;
        res=char(t+48)+res;
    }
    while (res.size()>1&&res[0]=='0') res.erase(0,1);
    if(neg==1) res="-"+res;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("sub2so.INP","r",stdin);
    freopen("sub2so.OUT","w",stdout);
    cin>>a>>b;
    cout<<sub(a,b);
    return 0;
}

