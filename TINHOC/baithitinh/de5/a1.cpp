#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7;
int n,k;
int a[N];
long long s,s1;
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
    freopen("a1.inp","r",stdin);
    freopen("a1.out","w",stdout);
    read(n);
    read(k);
    for(int i=1;i<=n;i++) read(a[i]),s+=a[i];
    sort(a+2,a+n+1);
    for(int i=n;i>=n-k+1;i--) s1+=a[i];
    cout<<s-2*s1;
}
