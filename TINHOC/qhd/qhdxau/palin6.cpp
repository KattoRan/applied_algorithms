#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int n,k;
string f[maxn][maxn];
string s,t;
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
void xuli()
{

      for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
      f[i][j]="0";
      for (int i = 1;i<=n;i++) f[i][i]="1";
      for (int i = n-1;i>=1;i--)
           for (int j=i+1;j<=n;j++)
                   {
                       f[i][j]=add(f[i][j-1],f[i+1][j]);
                       if (s[i]==s[j]) f[i][j]=add(f[i][j],"1");
                       else f[i][j]=sub(f[i][j],f[i+1][j-1]);
                   }
}
int main()
{
    cin>>s;
    n=s.size();
    s="="+s;
    xuli();
    cout<<f[1][n];
    return 0;
}
