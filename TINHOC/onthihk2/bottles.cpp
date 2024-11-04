///___LAN___\\\

#include <bits/stdc++.h>
using namespace std;
#define  fi first
#define  se second
#define  ll long long
#define  up(i,a,b) for(int i =  a ; i <= b ; ++i)
#define  dw(i,a,b) for(int i =  a ; i >= b ; --i)
void read(){}
template <typename Head,typename ...Tail>
inline void read(Head &H,Tail &...T)
{
    H=0;
    char c=getchar();
    bool am=0;
    while(!isdigit(c))am=am|(c=='-'),c=getchar();
    while(isdigit(c))H=H*10+c-'0',c=getchar();
    if(am)H=-H;
    read(T...);
}
const int N=1e6+7;
const int ooi=INT_MAX;
const ll  ool=LLONG_MAX;
const int mod=1e9+7;
typedef   pair<int,int> ii;

bool lay[N];
ll a[N],b[N],n,k,f[N],s[N],trc[N];
deque<int>q;

int main()
{
    #define name ""
    ios_base:: sync_with_stdio(0),cin.tie(0),cout.tie(0);
//    freopen(name".inp","r",stdin);
//    freopen(name".out","w",stdout);

    read(n,k);
    up(i,1,n)read(a[i]),s[i]=s[i-1]+a[i],lay[i]=1;
    up(i,1,k-1)
    {
        b[i]=a[i];
        while(q.size()&&b[q.back()]>=b[i])q.pop_back();
        q.push_back(i);
        f[i]=s[i];
    }
    up(i,k,n)
    {
        b[i]=s[i]-f[i-1];
        while(q.size()&&b[q.back()]>=b[i])q.pop_back();
        q.push_back(i);
        while(i-q.front()>=k)q.pop_front();
        f[i]=s[i]-b[q.front()];
        trc[i]=q.front();
    }
    int i=trc[n];
    int ptu=0;
    while(i)
    {
        ptu++;
        lay[i]=0;
        i=trc[i-1];
    }

    cout<<n-ptu<<" "<<f[n]<<'\n';
    up(i,1,n)if(lay[i])cout<<i<<" ";

    return 0;
}


