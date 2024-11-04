// Cat \\
||*---*||
#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define catlan main
#define bit(X,i) ((X>>i)&1)
#define on(X,i) (X|(1<<i))
#define off(X,i) (X^(1<<i))
#define dembit(X) __builtin_popcount(X)
using namespace std;

const int N=1e6+7;

typedef long long ll;
typedef pair<int,int> ii;
int n,x;

template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-')
    {
        tam=-1;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}

void ent()
{
   cin>>n;
}

void solve()
{
   while(n--)
    {
        cin>>x;
        ll dem=sqrt(x);
        ll k=x-dem*dem;
        if(dem*dem!=x) dem++;
        if(k==0)
        {
            cout<<1<<"\n";
            continue;
        }
        if(k>dem)
        cout<<dem*2-k<<"\n";
        else
            cout<<k<<"\n";
    }
}

catlan()
{
    #define name "infinity"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    ent();
    solve();
}
/*
#include<bits/stdc++.h>
using namespace std;

string sum(string a,string b){
    while(a.size()>b.size())b='0'+b;
    while(a.size()<b.size())a='0'+a;
    string res="";
    int t=0,nho=0;
    for(int i=a.size()-1;i>=0;i--){
        t=a[i]+b[i]-96+nho;
        nho=t/10;
        t%=10;
        res+=char(t+48);
    }
    if(nho)res+='1';
    reverse(res.begin(),res.end());
    return res;
}

string div(string s){
    int t=0;
    string res="";
    for(auto i:s){
        t=t*10+i-'0';
        int div2=t/2;
        res+=char(div2+48);
        t=t-div2*2;
    }
    while(res[0]=='0'&&res.size()>1)res.erase(0,1);
    return res;
}

string mul(string a,string b){
    int n=a.size();
    int m=b.size();
    int cs=m+n;
    int t=0,nho=0;
    string res="";
    for(int i=cs-1;i>=0;i--){
        for(int j=n-1;j>=0;j--){
            if(i-j>0&&i-j<=m){
                t+=int(a[j]-48)*(b[i-j-1]-48);
            }
        }
        res+=char(int(t%10)+48);
        t/=10;
    }
    reverse(res.begin(),res.end());
    while(res.size()>1&&res[0]=='0')res.erase(0,1);
    return res;
}

string tru(string a,string b){
    while(a.size()>b.size())b='0'+b;
    while(a.size()<b.size())a='0'+a;
    string res="";
    int t=0,nho=0;
    for(int i=a.size()-1;i>=0;i--){
        t=a[i]-b[i]+nho;
        nho=0;
        if(t<0)nho=-1,t+=10;
        res+=char(t+48);
    }
    reverse(res.begin(),res.end());
    while(res.size()>1&&res[0]=='0')res.erase(0,1);
    return res;
}

bool bigger(string a,string b){
    if(a.size()==b.size())return a>=b;
    else return a.size()>b.size();
}

string count_number(long long value){
    stringstream ss;
    ss<<value;
    string s;
    ss>>s;
    string big=tru(mul(s,"2"),"1");
    string small="1";
    s=div(mul(sum(big,small),s));
    return s;
}

long long calc(string s){
    long long l=1,r=1e16,res1=0;
    while(l<=r){
        long long mid=(l+r)/2;
        if(bigger(count_number(mid),s)){///mid>=val can tim
            res1=mid;
            r=mid-1;
        }
        else l=mid+1;
    }
    string tmp=count_number(res1-1);
    string conlai=tru(s,tmp);
    stringstream ss;
    ss<<conlai;
    long long res;
    ss>>res;
    if(res<=res1)return res;
    else return res1-res+res1;
}

int main(){
    #define name "infinity"
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);

    int test;
    cin>>test;
    while(test--){
        string s;
        cin>>s;
        cout<<calc(s)<<'\n';
    }
}

sum=(l+b)*ssh/2;
ssh=(l-b)/2+1;


*/
