#include<bits/stdc++.h>
#define task "nhiphan1"
using namespace std;
int n;
string a,b;
int cmp(string a,string b)
{
    if(a.size()<b.size()) return 0;
    if(a.size()>b.size()) return 1;
    if(a<=b) return 0;
    return 1;
}
string add(string a,string b)
{
    string res;
    int t,nho;
    while(a.size()<b.size())
        a="0"+a;
    while(b.size()<a.size())
        b="0"+b;
    res="";
    nho=0;
    for(int i=a.size()-1; i>=0; i--)
    {
        t=a[i]+b[i]-96+nho;
        nho=t/10;
        t=t%10;
        res=char(t+48)+res;
    }
    if(nho>0)
        res="1"+res;
    return res;
}
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
string mul(string a,string b)
{
    string res="";
    int n=a.size();
    int m=b.size();
    int len=m+n-1;
    int nho=0;
    for(int i=len;i>=0;i--)
    {
        int tmp=0;
        for(int j=n-1;j>=0;j--)
            if(i-j<=m&&i-j>=1)
        {
            int a1=a[j]-48;
            int b1=b[i-j-1]-48;
            tmp+=a1*b1;
        }
        tmp+=nho;
        nho=tmp/10;
        res=char(tmp%10+48)+res;
    }
    while(res.size()>1&&res[0]=='0') res.erase(0,1);
    return res;
}
string f[105];
string xuli1(string a)
{
    string res="0";
    int n=a.size()-1;
    for(int i=0;i<=n;i++)
        if(a[i]=='1') res=add(res,f[n-i]);
    return res;
}
string xuli2(string b)
{
    string res="";
    for(int i=1;i<=n;i++)
        if(cmp(f[n-i],b)==0) b=sub(b,f[n-i]),res+="1";
        else res+="0";
    return res;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    cin>>n;
    f[0]="1";
    for(int i=1;i<=n;i++)
        f[i]=mul(f[i-1],"2");
    cin>>a;
    cout<<add(xuli1(a),"1")<<'\n';
    cin>>b;
    b=sub(b,"1");
    cout<<xuli2(b);
}
