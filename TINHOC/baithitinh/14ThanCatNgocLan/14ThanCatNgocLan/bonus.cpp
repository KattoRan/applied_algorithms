#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
const long long oo=1e18+7;
int n,m,d;
int a[N],b[N];
long long res;
void read(int &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-')
    {
        c=getchar();
        tam=-1;
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}
void sub1()
{
    fu(i,1,n)
    fu(j,1,m)
    res=max(res,(long long)a[i]*b[j]);
    cout<<res;
}
void sub2()
{
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    if(a[n]*b[n]>0)
        if(a[1]*b[1]<=0) res=a[n]*b[n];
        else res=max(a[n]*b[n],a[1]*b[1]);
    else
        res=max(a[1]*b[n],a[n]*b[1]);
    cout<<res;
}
main()
{
    #define name "bonus"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    read(m);
    fu(i,1,n) read(a[i]);
    fu(i,1,m) read(b[i]);
    if(n<=1007&&m<=1007) sub1();
    else sub2();
}
