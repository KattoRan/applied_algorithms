#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int t,m,p[N],f[N],a[N],k=0;
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
/*void phantich(long long x)
{
    int d,k=0;
    int i=2;
    while(x>=i*i)
    {
        d=0;
        while(x%i==0){d++,x/=i;}
        if(d>0)
        {
            k++;
            m[k]=d;
            p[k]=i;
        }
        i++;
    }
    if(x>1) {k++;m[k]=1;p[k]=x;}
}*/
void sang()
{
    f[0]=1;f[1]=1;
    for(int i=2;i*i<=1000000;i++)
    if(f[i]==0)
    for(int j=i*i;j<=1000000;j+=i)
    if(f[j]==0)f[j]=1;
    for(int i=2;i<=1000000;i++)
        if(f[i]==0)
    {
        k++,a[k]=i;
    }
}
void phantich(int x)
{
    int d=0;
    int j=1;
    int i=a[j];
    while(x>=i*i)
    {
        while(x%i==0&&x/i>1)
        {
            d++;
            p[d]=i;
            cout<<p[d]<<"*";
            x/=i;
        }
        j++;i=a[j];
    }
    cout<<x<<'\n';
}
main()
{
    #define name "factor"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(t);
    sang();
    while(t--)
    {
        read(m);
        phantich(m);
    }
}
