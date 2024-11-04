#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
int m,n,a[N],b[N],s;
long long l[N],d;
template <typename T> inline void read(T& x)
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
void solve1()
{
    int s=*max_element(b+1,b+m+1);
    l[0]=1;
    fu(i,1,n)
    for(int j=s; j>=0; j--)
        if(j+a[i]<=s&&l[j]!=0)
            l[a[i]+j]=1;
    fu(i,1,m)
    if(l[b[i]])
        d++;
    cout<<d;
}
main()
{
    #define name "A3"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    read(m);
    fu(i,1,n) read(a[i]);
    fu(i,1,m) read(b[i]);
    solve1();
}
