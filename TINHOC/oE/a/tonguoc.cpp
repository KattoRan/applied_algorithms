#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
using namespace std;
const int N=1e6+7;
int n,f[N];
string res;
map<int,int> m;
void sang()
{
    int k=0;
    f[0]=1;
    f[1]=1;
    for(int i=1;i*i<=n;i++)
        if(f[i]==0)
        for(int j=i*i;j<=n;j+=i)
        if(f[j]==0) f[j]=1;
    for(int i=1;i<=n;i++)
        if(f[i]==0) k++,f[k]=i;
}
void phantich(int x)
{
    int i=1;
    while(f[i]*f[i]<=x)
    {
        while(x%f[i]==0)
        {
            m[f[i]]++;
            x/=f[i];
        }
        i++;
    }
    if(x>1) m[x]++;
}
string cd(long long x)
{
    string res;
    while(x!=0)
    {
        res=char(x%10+48)+res;
        x/=10;
    }
    return res;
}
string operator+(string a,string b)
{
    string res="";
    while(a.size()<b.size()) a="0"+a;
    while(a.size()>b.size()) b="0"+b;
    int nho=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        int tmp=a[i]+b[i]-96+nho;
        nho=tmp/10;
        tmp=tmp%10;
        res=(char)(tmp+48)+res;
    }
    if(nho==1) res="1"+res;
    return res;
}
string operator-(string a,string b)
{
    string res="";
    while(a.size()<b.size()) a="0"+a;
    while(a.size()>b.size()) b="0"+b;
    bool neg=0;
    if(a<b){swap(a,b);neg=1;}
    int muon=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        int tmp=a[i]-b[i]-muon;
        if(tmp<0){tmp+=10;muon=1;}
        else muon=0;
        res=(char)(tmp+48)+res;
    }
    while(res.size()>1&&res[0]=='0') res.erase(0,1);
    if(neg==1) res="-"+res;
    return res;
}
string operator*(string a,string b)
{
    string res;
    int n=a.size();
    int m=b.size();
    int len=n+m-1;int carry=0;
    for(int i=len;i>=0;i--)
    {
        int tmp=0;
        for(int j=n-1;j>=0;j--)
        if(i-j<=m && i-j>=1)
        {
            int a1=a[j]-48;
            int b1=b[i-j-1]-48;
            tmp+=a1*b1;
        }
        tmp+=carry;
        carry=tmp/10;
        res=(char)(tmp%10+48)+res;
    }
    while(res.size()>1 && res[0]=='0') res.erase(0,1);
    return res;
}
bool cmp(string a,string b)
{
    while(a.size()>b.size()) b="0"+b;
    while(a.size()<b.size()) a="0"+a;
    if(a>=b) return 1;
    else return 0;
}
string operator/(string a,string b)
{
    string res="",hold="",kb[11];
    kb[0]="0";
    for(int i=1;i<=10;i++) kb[i]=kb[i-1]+b;
    for(int i=0;i<a.size();i++)
    {
        hold=hold+a[i];
        int k=1;
        while(cmp(hold,kb[k])&& k<10) k++;
        k--;
        hold=hold-kb[k];
        res=res+char(k+48);
    }
    while(res.size()>1&&res[0]=='0') res.erase(0,1);
    return res;
}
string lt(int n,int k)
{
    if(k==0) return "1";
    if(k==1) return cd(n);
    if(k%2==0) return lt(n,k/2)*lt(n,k/2);
    if(k%2==1) return lt(n,k/2)*lt(n,k/2)*cd(n);
}
string k="1";
void solve()
{
    res="1";
    for(auto i:m)
    {
        k=k*cd(i.se+1);
    }
    cout<<k<<endl;
    for(auto i:m)
    {
        string dm=lt(i.fi,i.se+1);
        string dmm=(dm-"1")/(cd(i.fi)-"1");
        res=res*dmm;
    }
    cout<<res;
}
main()
{
    #define name "tonguoc"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>n;
    sang();
    for(int i=2;i<=n;i++)
        phantich(i);
    solve();
}
