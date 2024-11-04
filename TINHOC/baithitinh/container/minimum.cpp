// Cat \\
||*---*||
#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
using namespace std;

const int N=1e6+7;

typedef long long ll;
typedef pair<int,int> ii;
int n,a[N],k;
deque<int> q;
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
     read(k);
     fu(i,1,n) read(a[i]);
}

void solve()
{
     fu(i,1,k-1)
     {
         while(q.size()&&a[q.back()]>=a[i]) q.pop_back();
         q.push_back(i);
     }
     fu(i,k,n)
     {
         while(q.size()&&a[q.back()]>=a[i]) q.pop_back();
         if(q.front()==i-k) q.pop_front();
         q.push_back(i);
         cout<<a[q.front()]<<'\n';
     }
}

main()
{
    #define name "minimum"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    nhap();
    solve();
}
