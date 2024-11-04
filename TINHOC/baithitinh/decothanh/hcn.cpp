#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
struct hcn{int ma,vt;} a[N];
int n,res,mx,a1;
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
bool cmp(hcn a, hcn b)
{
    if(a.ma==b.ma)return a.vt<b.vt;
    return a.ma<b.ma;
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("hcn.inp","r",stdin);
    freopen("hcn.out","w",stdout);
    read(n);
    fu(i,1,n)
    {
        int x,y,z,t;
        read(x);
        read(y);
        read(z);
        read(t);
        if(mx<x)
        {
            mx=x;
            a1=i;
        }
        a[i]=hcn{z,i};
    }
    sort(a+1,a+n+1,cmp);
    cout<<mx-a[1].ma;
    cout<<'\n'<<a[1].vt<<" "<<a1;
}


