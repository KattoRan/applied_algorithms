#include<bits/stdc++.h>
using namespace std;
string m,n;
string sub(string a,string b)
{
    string res="";
    while(a.size()>b.size()) b='0'+b;
    while(b.size()>a.size()) a='0'+a;
    int tam=0,nho=0;
    if(a<b) {swap(a,b);tam=1;}
    for(int i=a.size()-1;i>=0;i--)
    {
        int tmp=a[i]-b[i]-nho;
        if(tmp<0) {tmp+=10;nho=1;}
        else nho=0;
        res=char(tmp+48)+res;
    }
    while(res.size()>1&&res[0]=='0') res.erase(0,1);
    if(tam==1) res='-'+res;
    return res;
}
main()
{
    #define name "sub2so"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>m>>n;
    cout<<sub(m,n);
}
