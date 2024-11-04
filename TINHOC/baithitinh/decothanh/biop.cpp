#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
int n,a[N],b[N];
pair<int,int> d[N];
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
    #define name "biop"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(name".inp","r",stdin);
	freopen(name".out","w",stdout);
    read(n);
    fu(i,1,n) read(a[i]),b[i]=a[i];
    sort(b+1,b+n+1);
    fu(i,1,n)
    {
        int j=lower_bound(b+1,b+n+1,a[i])-b;
        if(j==n+1) d[i].first=n;
        else d[i].first=j-1;
        int k=upper_bound(b+1,b+n+1,a[i])-b;
        if(j==n+1) d[i].second=0;
        else d[i].second=n-k+1;
    }
    fu(i,1,n) cout<<d[i].first<<" "<<d[i].second<<'\n';
}

