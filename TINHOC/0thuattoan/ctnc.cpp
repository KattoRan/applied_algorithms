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

}

void solve()
{

}

string operator+ (string a,string b)
{
    string res="";
    int nho=0;

    while (a.size() < b.size()) a='0'+a;
    while (b.size() < a.size()) b='0'+b;

    for(int i=a.size() - 1; i>=0; i--)
    {
        int x = a[i] + b[i] -96 + nho;
        nho = x/10;
        x = x%10;
        res= (x + 48) + res;
    }
    if(nho == 1) res = "1" + res;
    return res;
}

string operator- (string a,string b)
{
    string res="";
    int nho=0, tam=0;

    while (a.size() < b.size()) a='0'+a;
    while (b.size() < a.szie()) b='0'+b;

    if(a<b) swap(a,b), tam=1;

    for(int i=a.size() - 1; i>=0; i--)
    {
        int x = a[i] - b[i] - nho;
        if (x < 0)
        {
            nho=1;
            x = x + 10;
        }
        res = (x+48) + res;
    }

    while (res.size() > 1 && res[0] == '0') res.erase(0,1);
    if (tam==1) res = "-" +res;
    return res;
}

string operator* (string a,string b)
{
    string res="";
    int n=a.size() , m=b.size();
    int len = m+n-1,nho = 0;
    for(int i = len; i >= 0; i--)
    {
        int tmp = 0;
        for(int j = n-1; j >= 0; j--)
            if(i-j <= m && i-j > 0)
        {
            int a1 = a[j] - 48;
            int b1 = b[i-j-1] -48;
            tmp += a1*b1;
        }
        tmp += nho;
        nho = tmp/10;
        res = (tmp%10 + 48) + res;
    }

    while (res.size() > 1 && res[0] == '0') res.erase(0,1);
    return res;
}

bool cmp (string a, string b)
{
    if (a.size() < b.size()) return 1;
    if (a.size() > b.size()) return 0;
    if (a==b) return 1;
}

string operator/ (string a,string b)
{
    string res="";
    string hold="", kb[11];
    kb[0]="";
    for(int i=1; i<=10; i++) kb[i] = kb[i-1]+b;
    for(int i=0; i<a.size(); i++)
    {
        hold=hold+a[i];
        int k=1;
        while (cmp(hold,kb[k])&&k<10) k++;
        k--;
        hold=hold-kb[k];
        res=res+char(k+48);
    }
    while(res.size()>1&&res[0]=='0') res.erase(0,1);
    return res;
}

string cd (long long x)
{
    string res="";
    while(x>0)
    {
        res= (x%10+48) +res;
        x/=10;
    }
    return res;
}

string sqr(string a)
{
    return a*a;
}

string lt(int n,int k)
{
    if(k==0) return "1";
    else if(k%2==0) return sqr(lt(n,k/2));
    else return cd(n)*sqr(lt(n,k/2));
}
// pow(x,y)= x^y;
catlan()
{
    #define name ""
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    ent();
    solve();
}
