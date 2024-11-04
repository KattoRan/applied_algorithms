#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define catlan main
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e6+7;
long long n;
int a[N],d[N],dd[N],dem;
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
catlan()
{
#define name "diffval"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    fu(i,1,n) read(a[i]);
    fu(i,1,n)
    {
        if(d[a[i]]==0) dem++,dd[i]=1;
        else dd[i]=0;
        d[a[i]]++;
    }
    cout<<dem<<'\n';
    fu(i,1,n)
    if(dd[i]) cout<<a[i]<<" "<<d[a[i]]<<'\n';
}



