#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,k;
long long a[N];
template<typename T> inline void read(T& x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-')
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
    #define name "dayso"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    read(k);
    a[1]=1;
    a[2]=1;
    for(int i=3;i<=n;i++)
    {
        a[i]=(a[i-1]%128+a[i-2]%128)%128;
    }
    sort(a+1,a+n+1);
    cout<<a[k];
}
