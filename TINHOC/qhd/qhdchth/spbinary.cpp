#include<bits/stdc++.h>
#define task "spbinary"
using namespace std;
const int N=607;
int n,k;
string f[N][2],l[N];
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
void xuli1()
{
    f[0][0]=f[0][1]=f[1][0]=f[1][1]='1';
    for(int i=2;i<=k;i++)
        for(int j=0;j<=1;j++)
        f[i][j]=add(f[i-1][0],f[i-1][1]);
    for(int i=k+1;i<=n;++i)
        for(int j=0;j<=1;j++)
        f[i][j]=sub(add(f[i-1][0],f[i-1][1]),f[i-k-1][1-j]);
    cout<<add(f[n][1],f[n][0]);
}
void xuli2()
{
    l[0]="1";
    for(int i=1;i<=k;i++)
        l[i]=mul(l[i-1],"2");
    for(int i=k+1;i<=n;i++)
    {
        l[i]="0";
        for(int j=i-k;j<=i-1;j++)
            l[i]=add(l[i],l[j]);
    }
    cout<<l[n];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".INP","r",stdin);
    freopen(task".OUT","w",stdout);
    cin>>n>>k;
    xuli2();
    return 0;
}

