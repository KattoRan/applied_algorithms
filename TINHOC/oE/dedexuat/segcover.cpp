#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,a[N],b[N];
template<typename T> inline void read(T& x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit()&&c!='-')
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
main()
{
    read(n);
    for(int i=1;i<=n;i++)
    {read(a[i]);read(b[i]);}
}
