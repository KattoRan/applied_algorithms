#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e6+7;
int n,k,s;
int a[N],tr[N],f[N],cx[N];
int sb,sl;
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
    #define name "expr"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(name".inp","r",stdin);
	freopen(name".out","w",stdout);
    read(n);
    read(k);
    fu(i,1,n) read(a[i]);
    fu(i,1,n) s+=a[i];
    sl=(s+k)/2;
    sl-=a[1];
    f[0]=1;
    fu(i,2,n)
    fd(j,sl,0)
    {
        if(j>=a[i])
        {
            f[j]=f[j-a[i]];
            if(f[j]==1&&tr[j]==0)
                tr[j]=i;
        }
    }
    int i=sl;
    while(i>0)
    {
        cx[tr[i]]=1;
        i=i-a[tr[i]];
    }
    fu(i,2,n)if(cx[i]==0)
        cout<<'-';
    else
        cout<<'+';

}
