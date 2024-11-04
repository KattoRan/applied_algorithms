#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
int n,k;
long long res;
int a[N];
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
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("pairnum.inp","r",stdin);
    freopen("pairnum.out","w",stdout);
    read(n);
    read(k);
    fu(i,1,n) read(a[i]);
    sort(a+1,a+n+1);
    fu(i,1,n)
    {
        int j=lower_bound(a+i+1,a+n+1,k-a[i])-a;
        res+=n-j+1;
        res=res%1000000000;
    }
    cout<<res;

}
