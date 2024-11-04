// Cat \\
||*---*||
#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
const int N=1e5+7;
struct ql{int a,b,c,k;} p[N];
int n,f[N],cs,kq[N],tr[N];
long long res;

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

bool cmp(ql i,ql j)
{
    if(i.a==j.a)
        return i.b<j.b;
    return i.a<j.a;
}

void nhap()
{
    read(n);
    fu(i,1,n)
    {
        read(p[i].a);
        read(p[i].b);
        read(p[i].c);
        p[i].k=i;
    }
}

void solve()
{
    sort(p+1,p+n+1,cmp);
    fu(i,1,n) f[i]=p[i].c;
    fu(i,2,n)
    fd(j,i-1,1)
    {
        if(p[i].a>p[j].b) f[i]=max(f[i],f[j]+p[i].c);
        if(f[i]==f[j]+p[i].c) tr[i]=j;
    }
    res=f[1];
    fu(i,2,n)
        if(f[i]>res) res=f[i],cs=i;
}

void vet()
{
    int d;
    d=1;
    kq[d]=p[cs].k;
    while(tr[cs]!=0)
    {
        d++,kq[d]=p[tr[cs]].k,cs=tr[cs];
    }
    cout<<d<<" "<<res<<'\n';
    fd(i,d,1) cout<<kq[i]<<" ";
}
main()
{
    #define name "computer"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    nhap();
    solve();
    vet();
}
