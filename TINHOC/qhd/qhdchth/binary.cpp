#include<bits/stdc++.h>
#define task "binary"
using namespace std;
const int N=107;
int n,k,x;
string f[N],l[N][N];
string p;
string res1,res;
int c[N];
int cmp(string a,string b)
{
    if(a.size()<b.size())
        return 0;
    if(a.size()>b.size())
        return 1;
    if(a<=b)
        return 0;
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
    while(a.size()<b.size())
        a="0"+a;
    while(b.size()<a.size())
        b="0"+b;
    if(a<b)
        swap(a,b);
    res="";
    nho=0;
    for(int i=a.size()-1; i>=0; i--)
    {
        t=a[i]-b[i]-nho;
        if(t<0)
        {
            t=t+10;
            nho=1;
        }
        else
            nho=0;
        res=char(t+48)+res;
    }
    while(res[0]=='0'&&res.size()>1)
        res.erase(0,1);
    return res;
}
string mul(string a,string b)
{
    string res="";
    int n=a.size();
    int m=b.size();
    int len=m+n-1;
    int nho=0;
    for(int i=len; i>=0; i--)
    {
        int tmp=0;
        for(int j=n-1; j>=0; j--)
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
    while(res.size()>1&&res[0]=='0')
        res.erase(0,1);
    return res;
}
string xuli1()
{
    string res,res1="0";
    string v;
    int k1=k;
    for(int i=1;i<=n;i++)
        if(c[i]==1)
        {
            v=f[n-i];
            res="0";
            for(int j=k1+1; j<=n-i; j++)
                res=add(res,l[n-i][j]);
            k1--;
            res1=add(res1,sub(v,res));
        }
    res1=add(res1,"1");
    return res1;
}
void xuli2()
{
    string d2="";
    int k1=k;
    string p1=sub(p,"1");
    for(int i=1;i<=n;i++)
    {
        string x1=f[n-i];
        string x2="";
        for(int j=k1+1;j<=n-i;j++)
        x2=add(x2,l[n-i][j]);
        string x3=sub(x1,x2);
        if(cmp(p1,x3))
        {
            p1=sub(p1,x3);
            d2+="1";
            k1--;
        }
        else d2+="0";
    }
    for(int i=0;i<d2.size();i++)
        cout<<d2[i]<<" ";
    cout<<endl;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>k;
    f[0]="1";
    for(int i=1; i<=n; i++)
        f[i]=mul(f[i-1],"2");
    for(int i=0; i<=n; i++)
        l[i][0]="1",l[i][i]="1";
    for(int i=1; i<=n; i++)
        for(int j=1; j<=i; j++)
            l[i][j]=add(l[i-1][j],l[i-1][j-1]);
    res="0";
    for(int i=0; i<=k; i++)
        res=add(res,l[n][i]);
    cout<<res<<'\n';
    int x;
    while(cin>>x)
    {
        if(x==1)
        {
            for(int i=1;i<=n;i++) cin>>c[i];
            cout<<xuli1()<<'\n';
        }
        if(x==2)
        {
            cin>>p;
            p=add(p,"1");
            xuli2();
        }
    }

}
