#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
double a[N],r,d1[N];
int n,d;
template <typename T> inline void read(T&x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-')
        c=getchar();
    if(c=='-') tam=-1,c=getchar();
    while(isdigit(c))
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}
main()
{
    #define name "camera"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>n>>r;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    int i=1;
    while(i<=n)
    {
        int j=upper_bound(a+1,a+n+1,a[i]+2*r)-a;
        d++;
        i=j-1;
        i++;
    }
    cout<<d;
}
