#include<bits/stdc++.h>
#define task "select1"
using namespace std;
const int N=21;
int n,tmp;
long long t[1<<N];
long long a[N][N];
int b[N];
int getbit(int x,int k)
{
    return (x>>k)&1;
}
void xuli()
{
    for(int x=0;x<(1<<n);x++)
    {
        int d=0;
        for(int i=0;i<n;i++)
            if(getbit(x,i))
        {
            d++;
            b[d]=i+1;
        }
        for(int i=1;i<=d;i++)
        {
            tmp=0;
            int y=x^(1<<(b[i]-1));
            t[x]=max(t[x],t[y]+a[d][b[i]]);
        }
    }
    cout<<t[(1<<n)-1];
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>a[i][j];
    xuli();
}
