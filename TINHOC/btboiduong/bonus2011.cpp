#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+1;
const int oo=1e19+1;
int n,a[maxn][maxn],k;
long long s[maxn][maxn],res;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>a[i][j];
    res=-oo;
    for(int i=1;i<=n;i++)
       for(int j=1;j<=n;j++) s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
    for(int i=k;i<=n;i++)
        for(int j=k;j<=n;j++)
    {
        res=max(res,s[i][j]-s[i-k][j]-s[i][j-k]+s[i-k][j-k]);
    }
    cout<<res;
    return 0;
}
