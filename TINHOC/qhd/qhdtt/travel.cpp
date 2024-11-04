#include<bits/stdc++.h>
#define task "travel"
using namespace std;
const int N=17;
const int M=(1<<N)-1;
int n,m,res;
int c[N][N],t[N];
int f[N][M];
int getbit(int x,int k)
{
    return (x>>k)&1;
}
void xuli()
{
    for(int x=1;x<=m;x++)
    {
        int k=0;
        for(int i=1;i<=n;i++)
            if(getbit(x,i-1)) k++,t[k]=i;
        if(k>1)
        {
            for(int j=1;j<=k;j++)
            {
                int x1=x^(1<<(t[j]-1));
                f[t[j]][x]=1e9+7;
                for(int i=1;i<=k;i++)
                    if(i!=j&&f[t[j]][x]>f[t[i]][x1]+c[t[i]][t[j]])
                f[t[j]][x]=f[t[i]][x1]+c[t[i]][t[j]];
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++) cin>>c[i][j];
    m=(1<<n)-1;
    xuli();
    res=1e9+7;
    for(int i=1;i<=n;i++)
        res=min(res,f[i][m]);
    cout<<res;

}

