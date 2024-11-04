#include<iostream>
#include<algorithm>
using namespace std;
const int maxm=1e4+5;
const int maxn=305;
int l[maxn][maxm],m,n;
int a[maxn],res;
void khoitao()
{
    cin>>m>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
}
void xuly()
{
    for(int i=1; i<=n; i++)
        l[i][0]=0;
    for(int i=1; i<=m; i++)
        l[0][i]=1e6+5;
    l[0][0]=1;
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
        {
            if(a[i]>j)
                l[i][j]=l[i-1][j];
            else
                l[i][j]=min(l[i-1][j],1+l[i][j-a[i]]);
        }
    res=l[n][m];
}
int main()
{

    khoitao();
    xuly();
    cout<<res<<endl;
}
