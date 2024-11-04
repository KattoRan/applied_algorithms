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
const int N=1e6+7;
struct ql{int a,b;} p[N];
int n,f[N],f1[N];
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
    if(i.b==j.b) return i.a<j.a;
    return i.b<j.b;
}
void nhap()
{
    read(n);
    fu(i,1,n)
    {
        read(p[i].a);
        read(p[i].b);
        p[i].a=p[i].a+500000;
        p[i].b=p[i].b+500000;
        f1[p[i].b]=1;
    }
    sort(p+1,p+n+1,cmp);
}

void solve()
{
    f[1]=1;
    fu(i,2,n)
    {
        f[i]=0;
        fd(j,i-1,1)
        {
            if(p[j].b<p[i].a) break;
            if(p[j].b==p[i].a)
                if(f[j]>f[i]) f[i]=f[j];
        }
        f[i]+=1;
    }
    res=*max_element(f+1,f+n+1);
    cout<<res;
}
void solve1()
{
    fu(i,1,n)
    {
        f1[p[i].b]=max(f1[p[i].b],f1[p[i].a]+1);
    }
    res=*max_element(f1,f1+1000001);
    cout<<res;
}
main()
{
    #define name "doangoi"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    nhap();
    if (n<=1000)solve();
    else solve1();
}
