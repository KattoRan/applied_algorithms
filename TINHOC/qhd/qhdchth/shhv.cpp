#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define task ""
using namespace std;
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(task".inp","r",stdin);
    //freopen(task".out","w",stdout);
    cin>>n;
    f[1]="1";
    for(int i=2;i<=n;i++) f[i]=mul(f[i-1],i);
}
