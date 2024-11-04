#include<bits/stdc++.h>
#define task "sub2so"
using namespace std;
int n;
string a,b;
string sub(string a,string b)
{
    string res;
    int t,nho;
    int d=0;
    while(a.size()<b.size()) a="0"+a;
    while(b.size()<a.size()) b="0"+b;
    if(a<b) {swap(a,b);d=1;}
    res="";nho=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        t=a[i]-b[i]-nho;
        if(t<0) {t=t+10;nho=1;}
        else nho=0;
        res=char(t+48)+res;
    }
     while(res[0]=='0'&&res.size()>1)res.erase(0,1);
     if(d==1) res="-"+res;
    return res;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>a>>b;
    cout<<sub(a,b);
}
