#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int n,m,nl[maxn][maxn],a[maxn][maxn];
int tnl,x[maxn],cx[maxn],kq[maxn];
int res;
void nhap()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        nl[u][v]=nl[v][u]=c;
        a[u][v]=a[v][u]=1;
    }
    for(int i=1; i<=n; i++)
        a[0][i]=1,nl[0][i]=0;;
    x[0]=0;
    for(int i=1; i<=n; i++)
        cx[i]=1;
    tnl=0;
    res=0;
}
void cnkq()
{
    if(tnl+nl[x[n]][x[1]]>res)
    {
        res=tnl+nl[x[n]][x[1]];
        for(int i=1; i<=n; i++)
            kq[i]=x[i];
    }
}
void hamiton(int i)
{
    for(int j=1; j<=n; j++)
        if(cx[j]&&a[x[i-1]][j])
        {
            x[i]=j;
            cx[j]=0;
            tnl+=nl[x[i-1]][j];
            if(i==n&&a[x[n]][x[1]])
                cnkq();
            else
                hamiton(i+1);
            tnl-=nl[x[i-1]][j];
            cx[j]=1;
        }
}
int main()
{
    nhap();
    hamiton(1);
    if(res!=0)
    {
        cout<<res<<endl;
        for(int i=1; i<=n; i++)
            cout<<kq[i]<<" ";
        cout<<kq[1];
    }
    else
        cout<<"-1";
    return 0;
}
