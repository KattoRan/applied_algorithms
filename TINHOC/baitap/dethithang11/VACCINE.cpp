#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+1;
long long p[maxn],n,dem,s,f1,f2;
map<long long,int> d;
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
    freopen("VACCINE.INP","r",stdin);
    freopen("VACCINE.OUT","w",stdout);
    read(n);
    for(int i=1; i<=n; i++)
        read(p[i]);
    int res=*max_element(p+1,p+n+1);
    f2=1;
    while(f1+f2<=res)
    {
        int f3=f1+f2;
        d[f3]=1;
        f1=f2;
        f2=f3;
    }
    dem=0;
    s=0;
    for(int i=1; i<=n; i++)
        if(d[p[i]]==0)
        {
            dem++;
            s+=p[i];
        }
    cout<<dem<<" "<<s;
    return 0;
}
