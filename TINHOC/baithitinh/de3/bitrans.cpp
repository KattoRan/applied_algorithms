#include<bits/stdc++.h>
using namespace std;
const int N=1007;
int n;
string f[N];
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
main()
{
    #define name "bitrans"
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen(name".inp","r",stdin);
	freopen(name".out","w",stdout);
    while(cin>>n)
    {
        f[1]="0";
        for(int i=2;i<=n;i++)
        {
            if(i%2==1) f[i]=sub(mul(f[i-1],"2"),"1");
                else f[i]=add(mul(f[i-1],"2"),"1");
        }
        cout<<f[n]<<'\n';
    }
}
