#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int n;
string x;
int l[maxn][maxn];
void init()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("palin2.inp","r",stdin);
    freopen("palin2.out","w",stdout);
    cin>>x;
    n=x.size();
    x="+"+x;
}
void tinh()
{
    for(int i=1;i<=n;i++) l[i][i]=0;
    for(int j=2;j<=n;j++)
        for(int i=j-1;i>=1;i--)
    {
        if(x[i]!=x[j]) l[i][j]=min(l[i+1][j],l[i][j-1])+1;
        else l[i][j]=l[i+1][j-1];
    }
}
int main()
{
    init();
    tinh();
    cout<<l[1][n];
    return 0;
}
