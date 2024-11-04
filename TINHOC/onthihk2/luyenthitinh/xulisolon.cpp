#include<bits/stdc++.h>
using namespace std;
string m,n;
long long x;
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
string cd(long long x)
{
    string res="";
    int tmp;
    while(x>0)
    {
        tmp=x%10;
        x=x/10;
        res=char(tmp+48)+res;
    }
    return res;
}

main()
{
    cin>>m>>n;
    cout<<add(m,n)<<" "<<sub(m,n);
    cin>>x;
    m=cd(x);
    cout<<m;
}

