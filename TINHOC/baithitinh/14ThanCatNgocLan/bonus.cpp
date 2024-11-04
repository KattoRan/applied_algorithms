#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
const int oo=1e9+7;
int n,m,d;
int a[N],b[N],amx,ami,bmx,bmi;
long long res;
void read(int &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-')
    {
        c=getchar();
        tam=-1;
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}
main()
{
    #define name "bonus"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    read(m);
    amx=bmx=-oo;
    ami=bmi=oo;
    fu(i,1,n) read(a[i]),amx=max(amx,a[i]),ami=min(ami,a[i]);
    fu(i,1,m) read(b[i]),bmx=max(bmx,b[i]),bmi=min(bmi,b[i]);
    res=max((long long)amx*bmx,(long long)ami*bmi);
    res=max(res,(long long)ami*bmx);
    res=max(res,(long long)amx*bmi);
    cout<<res;
}
