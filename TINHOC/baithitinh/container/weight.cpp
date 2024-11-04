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
int n,a[N];
long long res;
stack<int> q;

template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-')
    {
        c=getchar();
        tam=-1;
    }
    while(isdigit(c))
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}
void nhap()
{
    read(n);
    fu(i,1,n) read(a[i]);
}

void solve()
{
    fu(i,1,n)
    fu(j,i,n)
    {
        int x=*max_element(a+i,a+j+1);
        int y=*min_element(a+i,a+j+1);
        res+=(x-y);
    }
    cout<<res;
}

main()
{
    #define name ""
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    nhap();
    solve();
}
