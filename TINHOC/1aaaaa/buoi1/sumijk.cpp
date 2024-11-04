#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define catlan main
using namespace std;
const int N=1e6+7;
long long n,a[N],dem;
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
void xuli1()
{
    dem=0;
    fu(i,1,n-2)
    fu(j,i+1,n-1)
    fu(k,j+1,n)
    if(a[i]+a[j]+a[k]==0) dem++;
    cout<<dem;
}
catlan()
{
    #define name "sumijk"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    fu(i,1,n) read(a[i]);
    xuli1();
}
