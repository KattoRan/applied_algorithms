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

const int N=1e3+7;

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
long long  m[N][N],a[N],n,x,y;
void RMQ(int n)
{
   for(int i=1;i<=n;i++) m[i][0]=i;
   for(int j=1; 1<<j <=n;j++)
       for(int i=1;i+(1<<j)-1 <=n;i++)
        if(a[m[i][j-1]]<a[m[i+(1<<(j-1))][j-1]]) m[i][j]=m[i][j-1];
       else m[i][j]=m[i+(1<<(j-1))][j-1];
}
void ent()
{
   cin>>n;
   fu(i,1,n) cin>>a[i];
}

void solve()
{
    fu(i,1,n)
    {fu(j,i+1,n)
    {
        int k=floor(log(j-i+1));
        if(a[m[i][k]]<=a[m[j-(1<<k)+1][k]])
            cout<<m[i][k]<<" ";
        else cout<<m[j-(1<<k)+1][k]<<" ";
    }
    cout<<endl;
    }
}

catlan()
{
    #define name ""
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    ent();
    RMQ(n);
    solve();
}
