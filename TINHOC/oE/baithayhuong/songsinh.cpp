#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,a[N],f[N],res1;
vector<int> b;
void sang()
{
    f[1]=1;
    f[0]=1;
    for(int i=2;i*i<=1000000;i++)
        if(f[i]==0)
        for(int j=i*i;j<=1000000;j+=i)
        if(f[j]==0) f[j]=1;
}
template <typename T> inline void read(T& x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-')
        c=getchar();
    if(c=='-') tam=-1,c=getchar();
    while(isdigit(c))
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}
int dao(int x)
{
    int res=0;
    while(x>0)
    {
        res=res*10+x%10;
        x/=10;
    }
    return res;
}
main()
{
    #define name "songsinh"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
    sang();
    for(int i=1;i<=n;i++)
        if(f[i]==0)
    {
        res1++;
        int y=dao(a[i]);
        if(f[y]==0) b.push_back(y);
    }
    cout<<res1<<'\n';
    for(int i=0;i<b.size();i++)
        cout<<b[i]<<" ";
}
