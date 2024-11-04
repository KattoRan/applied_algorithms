#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int n,k;
string f[maxn][2];
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
    while(a.size()<b.size()) a="0"+a;
    while(b.size()<a.size()) b="0"+b;
    if(a<b) swap(a,b);
    res="";nho=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        t=a[i]-b[i]-nho;
        if(t<0) {t=t+10;nho=1;}
        else nho=0;
        res=char(t+48)+res;
    }
     while(res[0]=='0'&&res.size()>1)res.erase(0,1);
    return res;
}
int main()
{
    cin>>n>>k;
    f[0][0]=f[0][1]=f[1][0]=f[1][1]='1';
    for(int i=2;i<=k;i++)
        for(int j=0;j<=1;j++)
        f[i][j]=add(f[i-1][0],f[i-1][1]);
    for(int i=k+1;i<=n;++i)
        for(int j=0;j<=1;j++)
        f[i][j]=sub(add(f[i-1][0],f[i-1][1]),f[i-k-1][1-j]);
    cout<<add(f[n][1],f[n][0]);
    return 0;
}


