#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define catlan main
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e6+7;
long long n;
ii a[N];
template <typename T> void read(T&x)
{
    int tam=1;
    char c=getchar();
    x=0;
    while(!isdigit(c)&&c!='-')
        c=getchar();
    if(c=='-')
        tam=-1,c=getchar();
    while(isdigit(c))
    {
        x=x*10+c-48;
        c=getchar();
    }
    x*=tam;
}
bool cmp(ii a,ii b)
{
    if(a.fi==b.fi) return a.se<b.se;
    else return a.fi<b.fi;
}
catlan()
{
    #define name "sxdoan"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>n;
    fu(i,1,n)
    {
        int x,y;
        cin>>x>>y;
        a[i]={x,y};
    }
    sort(a+1,a+n+1,cmp);
    fu(i,1,n)
    cout<<a[i].fi<<" "<<a[i].se<<'\n';
}
