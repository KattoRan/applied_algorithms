#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e6+7;
int n,a[N];
long long s;
template<typename T> inline void read(T& x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c=='-')
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
main()
{
    #define name "noinhanh"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name"inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    s=0;
    fu(i,1,n)
    {
        read(a[i]);
        s+=a[i];
        cout<<s<<" ";
    }
}
