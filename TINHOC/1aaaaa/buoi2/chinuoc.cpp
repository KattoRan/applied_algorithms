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
const int NN=1e12+1;

typedef long long ll;
typedef pair<int,int> ii;

ll t,n,f[N];

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

void sang()
{
    f[0]=1;
    f[1]=1;
    for(int i=2; i*i<=1000006; i++)
        if(f[i]==0)
            for(int j=i*i; j<=1000006; j+=i)
                if(f[j]==0)
                    f[j]=1;
    int k=0;
    for(int i=1; i<=1000006; i++)
        if(f[i]==0)
        {
            k++;
            f[k]=i;
        }
}

int solve()
{
    read(n);
    ll can=sqrt(n);
    int a=1,b,d=0;
    while(f[a]<=can/2)
    {
        b=a+1;
        while(f[a]*f[b]<=can)
        {
            d++;
            b++;
        }
        if(pow(f[a],8)<=n)
            d++;
        a++;
    }
    return d;
}

void ent()
{
    read(t);
    while(t--)
        cout<<solve()<<'\n';
}

catlan()
{
#define name "chinuoc"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    sang();
    ent();
}
