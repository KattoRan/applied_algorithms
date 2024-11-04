#include<bits/stdc++.h>
using namespace std;
int a,b,mmin,cmin,sumin;
map<int,int> m;
template <typename T> inline void read(T& x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-') c=getchar();
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
/*void phantich(long long x)
{
    int i=2,k=0,d;
    while(x>=i*i)
    {
        d=0;
        while(x%i==0)
            d++,x/=i;
        if(d>0) k++,m[k]=d,p[k]=i;
        i++;
    }
    if(x>1) k++,m[k]=1,p[k]=x;
}*/
main()
{
    #define name "uocso"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    cin>>a>>b;
    cmin=1;
    for(int i=a;i<=b;i++)
    {
        int d=2;
        int n=sqrt(i);
        for(int j=2;j<=n;j++)
        {
            if(i%j==0) d+=2;
        }
        if(n*n==i) d--;
        if(d>cmin) cmin=d,mmin=i;
        m[d]++;
    }
    cout<<mmin<<" "<<cmin<<" "<<m[cmin];
}
