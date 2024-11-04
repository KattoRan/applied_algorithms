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

int t,n,a[N],res;
ll s[N];

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

int chatnp(int l,int r)
{
    ll t1=s[r]-s[l-1];
    ll t2=t1/2;
    int j;
    if(t1==t2)
        j=lower_bound(s+l+1,s+r+1,t2+s[l-1])-s;
    else
        j=upper_bound(s+l+1,s+r+1,t2+s[l-1])-s;
    if(s[j-1]-s[l-1]!=t2||l>=r)
        return 0;
    return (max(chatnp(l,j-1),chatnp(j,r))+1);
}
void ent()
{
    read(t);
    while(t--)
    {
        s[0]=0;
        read(n);
        fu(i,1,n) read(a[i]),s[i]=s[i-1]+a[i];
        cout<<chatnp(1,n)<<endl;
    }
}

void solve()
{

}

catlan()
{
#define name "seq"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    ent();
    solve();
}
