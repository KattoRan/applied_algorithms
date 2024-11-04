#include<bits/stdc++.h>
#define fi first
#define se second
#define ull unsigned long long
#define ll long long
#define up(i,a,b) for(int i=a;i<=b;i++)
#define dw(i,a,b) for(int i=a;i>=b;i--)
int dx4[5]= {0,0,-1,0,1};
int dy4[5]= {0,-1,0,1,0};
int dx8[9]= {0,0,-1,-1,-1,0,1,1,1};
int dy8[9]= {0,-1,-1,0,1,1,1,0,-1};
#define randommode mt19937 rand(chrono::steady_clock::now().time_since_epoch().count());
const int mn=1e6+7;
const int mm=1e4+5;
const int oo=INT_MAX;
const ll ooo=LLONG_MAX;
const int mod=1e9+7;
typedef std::pair<int,int> ii;
using namespace std;

int d[300],n;

void ptich(int x)
{
    up(i,2,sqrt(x))
    {
        if(x%i==0)d[i]++,x/=i;
    }
    if(x>1)d[x]++;
}
string trans(ll x)
{
    stringstream ss;
    string res="";
    ss<<x;
    ss>>res;
    return res;
}
string operator+(string a,string b)
{
    while(a.size()>b.size())b='0'+b;
    while(a.size()<b.size())a='0'+a;
    int n=a.size()-1;
    int t=0,nho=0;
    string res="";
    dw(i,n,0)
    {
        t=a[i]+b[i]-96+nho;
        nho=t/10;
        t%=10;
        res=char(t+48)+res;
    }
    if(nho)res=char(nho+48)+res;
    return res;
}
string operator*(string a,string b)
{
    int n=a.size();
    int m=b.size();
    int cs=m+n-1;
    string res="";
    ll nho=0;
    dw(i,cs,0)
    {
        ll tmp=0;
        dw(j,n-1,0)
        {
            if(i-j>0&&i-j<=m)
            {
                int aa=a[j]-48;
                int bb=b[i-j-1]-48;
                tmp+=aa*bb;
            }
        }
        tmp+=nho;
        nho=tmp/10;
        tmp%=10;
        res=char(tmp+48)+res;
    }
    while(res.size()>1&&res[0]=='0')res.erase(0,1);
    return res;
}
int main()
{
    #define name "sumuoc"
    ios_base:: sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);

    cin>>n;

    up(i,1,n)
    {
        ptich(i);
    }

    string res="1";
    up(i,2,n)
    {
        if(d[i])
        {
            string tmp="1";
            string tmp2="1";
            string tmp3=trans(i);
            while(d[i])
            {
                tmp2=tmp2*tmp3;
                tmp=tmp+tmp2;
                d[i]--;
            }
            res=res*tmp;
        }
    }
    cout<<res;
}
