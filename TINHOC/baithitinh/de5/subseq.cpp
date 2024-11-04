#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
const int oo=1e9+7;
int n,m;
int a[N],l[N];
long long f[N];
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
    freopen("subseq.inp","r",stdin);
    freopen("subseq.out","w",stdout);
    read(n);
    read(m);
    fu(i,1,n) read(a[i]);
    fu(j,0,m) l[j]=oo;
    fu(i,1,n)
    for(int j=m;j>=0;j--)
    {
        if(j>=a[i])
            if(j==a[i]) l[j]=1;
            else l[j]=min(l[j],l[j-a[i]]+1);
    }
    if(l[m]==oo) cout<<"-1";
    else cout<<l[m];
}
