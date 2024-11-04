#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+1;
int a[maxn],n;
long long s[maxn],res;
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie();
    cout.tie();
    freopen("EVENMAX.INP","r",stdin);
    freopen("EVENMAX.OUT","w",stdout);
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    s[0]=0;
    res=0;
    for(int i=1;i<=n;i++)
        if(a[i]%2==0) {s[i]=s[i-1]+a[i];
                     res=max(res,s[i]);}
    cout<<res;
    return 0;
}

