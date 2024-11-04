#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int N=1e6+7;
const int oo=1e9+7;
int n,a,b;
typedef pair<int,int> ii;
ii d[N];
int tung[N],truc[N],res;
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
    #define name "minroad"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);read(a);read(b);
    for(int i=1;i<=n;i++) {read(d[i].fi);read(d[i].se);}
    sort(d+1,d+n+1);
    res=oo;
    for(int i=1;i<=n;i++)
        if(d[i].se==1) tung[i]=tung[i-1]+1,truc[i]=truc[i-1];
        else truc[i]=truc[i-1]+1,tung[i]=tung[i-1];
    for(int j=1;j<=n;j++)
    {
        if(tung[j]-a>=0)
        {int i=upper_bound(tung+1,tung+j+1,tung[j]-a)-tung;
        if(i!=j+1&&truc[j]-truc[i-1]>=b)
            res=min(res,d[j].fi-d[i].fi);}
        if(truc[j]-b>=0)
        {int k=upper_bound(truc+1,truc+j+1,truc[j]-b)-truc;
        if(k!=j+1&&tung[j]-tung[k-1]>=a)
            res=min(res,d[j].fi-d[k].fi);}
    }
    if(res!=oo)cout<<res;
    else cout<<"-1";

}
