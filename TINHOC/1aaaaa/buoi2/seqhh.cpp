// Cat \\
||*---*||
#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define catlan main
using namespace std;

const int N=1e6+7;

typedef long long ll;
typedef pair<int,int> ii;

int n,k,a[N];
ll s[N],d;
map<ll,int> m;

template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-')
        c=getchar();
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
    read(n);
    read(k);
    s[0]=0;
    fu(i,1,n) read(a[i]),s[i]=s[i-1]+a[i];
}

void solve()
{
    d=0;
    fu(i,1,n-1)
    fu(j,i+1,n)
    if(s[j]-s[i]==k)
        d++;
    cout<<d;
}

void solve2()
{
    d=0;
    m[0]=1;
    fu(i,1,n)
    {
        d+=m[s[i]-k];
        m[s[i]]++;
    }
    cout<<d;
}

catlan()
{
#define name "seqhh"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    ent();
    solve2();
}
