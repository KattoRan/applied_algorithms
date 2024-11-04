#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
const long long oo=1e17+9;
int n,a[N];
long long s,res;
int cs1,cs2;
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
    #define name "dayso"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(name".inp","r",stdin);
	freopen(name".out","w",stdout);
    read(n);
    fu(i,1,n) read(a[i]);
    res=-oo;
    int k;
    fu(i,1,n)
    {
        if(s==0) k=i;
        s+=a[i];
        if(s>res)
        {
            res=s;
            cs2=i;
            cs1=k;
        }
        if(s<0) s=0;
    }
    cout<<cs1<<" "<<cs2<<'\n';
    cout<<res;
}
