#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int m,n;
string x,y;
int l[maxn][maxn];
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("palin1.inp","r",stdin);
    freopen("palin1.out","w",stdout);
    cin>>x;
    m=x.size();
    for(int i=m-1;i>=0;i--) y+=x[i];
    n=y.size();
    x="+"+x;
    y="+"+y;
}
void tinh()
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
    {
        if(x[i]==y[j]) l[i][j]=l[i-1][j-1]+1;
        else l[i][j]=max(l[i-1][j],l[i][j-1]);
    }
}
int main()
{
    init();
    tinh();
    cout<<l[m][n];
    return 0;
}
