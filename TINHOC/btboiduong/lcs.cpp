#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
string x,y;
int n,m;
int f[maxn][maxn];
int main()
{
    cin>>x>>y;
    n=x.size();
    m=y.size();
    x="="+x;
    y="="+y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
    {
        if(x[i]==y[j]) f[i][j]=f[i-1][j-1]+1;
        else f[i][j]=max(f[i-1][j],f[i][j-1]);
    }
    cout<<f[n][m];
}
