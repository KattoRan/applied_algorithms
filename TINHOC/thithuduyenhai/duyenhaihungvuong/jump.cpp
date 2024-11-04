#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int n,a[maxn][maxn];
string f[maxn][maxn];
string add(string a,string b)
{
    string res;
    int t,nho;
    while(a.size()<b.size()) a="0"+a;
    while(b.size()<a.size()) b="0"+b;
    res="";nho=0;
    for(int i=a.size()-1;i>=0;i--)
    {
        t=a[i]+b[i]-96+nho;
        nho=t/10;
        t=t%10;
        res=(char)(t+48)+res;
    }
    if(nho>0) res="1"+res;
    return res;
}
int main()
{
    freopen("jump.inp","r",stdin);
    freopen("jump.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            cin>>a[i][j];
            f[i][j]="0";
        }
    f[1][1]="1";
    for(int i=1; i<=n; i++)
        for(int j=1; j<=n; j++)
        {
            int x=a[i][j];
            if(i==n&&j==n)
                cout<<f[n][n];
            if(i+x<=n)
                f[i+x][j]=add(f[i+x][j],f[i][j]);
            if(j+x<=n)
                f[i][j+x]=add(f[i][j+x],f[i][j]);
        }
}
