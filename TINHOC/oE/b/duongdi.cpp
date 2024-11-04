#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e3+7;
int n;
string f[N][N];
template<typename T> inline void read(T& x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c=='-')
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
string add(string a,string b)
{
    string res="";
    while(a.size()<b.size()) a="0"+a;
    while(a.size()>b.size()) b="0"+b;
    int nho=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        int x=a[i]+b[i]-96+nho;
        nho=x/10;
        x=x%10;
        res=char(x+48)+res;
    }
    if(nho==1) res="1"+res;
    return res;
}
main()
{
    #define name "duongdi"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(name"inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    fu(i,1,n)
    {
        f[1][i]="1";
        f[i][1]="1";
    }
    for(int i=2;i<=n;i++)
        for(int j=2;j<=n;j++)
        f[i][j]=add(f[i-1][j],f[i][j-1]);
    cout<<f[n][n];
}
