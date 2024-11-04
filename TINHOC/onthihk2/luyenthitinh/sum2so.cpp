#include<bits/stdc++.h>
using namespace std;
string m,n;
string add(string a,string b)
{
    string res="";
    while(a.size()>b.size()) b='0'+b;
    while(a.size()<b.size()) a='0'+a;
    int nho=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        int tmp=a[i]+b[i]-96+nho;
        nho=tmp/10;
        tmp=tmp%10;
        res=char(tmp+48)+res;
    }
    if(nho==1) res="1"+res;
    return res;
}
main()
{
    #define name "sum2so"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>m>>n;
    cout<<add(m,n);
}
