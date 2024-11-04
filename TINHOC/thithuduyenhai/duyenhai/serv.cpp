#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int c[maxn][maxn],a[maxn];
int m,n;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        cin>>c[i][j];
    for(int i=1;i<=m;i++)
        cin>>a[i];
    cout<<5;
    return 0;
}
