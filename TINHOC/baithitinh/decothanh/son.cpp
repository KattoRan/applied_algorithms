#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
int n,m,res;
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
     #define name "son"
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
     freopen(name".inp","r",stdin);
     freopen(name".out","w",stdout);
     read(n);
     read(m);
     fu(i,1,n)
     fu(j,1,n)if(i!=j)if(i<=m||j<=m)res++,cout<<i<<" "<<j<<endl;
     cout<<res;
}
