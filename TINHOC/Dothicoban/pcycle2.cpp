#include<bits/stdc++.h>
using namespace std;
const int maxn=207;
int n,m,b[maxn],d,dem,xo,dt;
int a[maxn][maxn],cx[maxn];
int tnl,nl[maxn][maxn];
vector<int> kq;
int s,gt;
void nhap()
{
    cin>>n>>m;
    s=0;
    gt=-1000007;
    for(int i=1; i<=m; i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        if(c>gt)
            gt=v;
        s+=c;
        a[u][v]=a[v][u]=1;
        nl[u][v]=nl[v][u]=c;
        b[u]++;
        b[v]++;
    }
    tnl=0;
    dt=0;
}
void DFS(int s)
{
    cx[s]=0;
    for(int i=1; i<=n; i++)
        if(cx[i]&&a[s][i])
            DFS(i);
}
bool kt()
{

    int dem=0;
    for(int i=1; i<=n; i++)
        cx[i]=1;
    DFS(1);
    for(int i=1; i<=n; i++)
        if(cx[i])
            d=1;
    if(d==1)
        return 0;
    return 1;
    for(int i=1; i<=n; i++)
        if(b[i]%2!=0)
            dem++;
    if(dem==0)
        return 1;
    else
    {
        if(dem==2)
            return 1;
        else
            return 0;
    }
}
bool lacau(int u,int v)
{
    for(int i=1; i<=n; i++)
        cx[i]=1;
    a[u][v]=a[v][u]=0;
    DFS(u);
    a[u][v]=a[v][u]=1;
    if(cx[v])
        return 1;
    return 0;
}
void euler(int x)
{
    kq.push_back(x);
    int ke;
    do
    {
        ke=0;
        for(int i=1; i<=n; i++)
            if(a[x][i]&&nl[x][i]<)
            {
                ke=i;
                if(!lacau(x,ke))
                    break;
            }
        if(ke!=0)
        {
            if(tnl+nl[x][ke]>=0)
            {
                kq.push_back(ke);
                tnl=tnl+nl[x][ke];
                a[ke][x]=a[x][ke]=0;
                x=ke;
            }
        }
    }
    while(ke!=0&&tnl>=0);
}
int main()
{
    nhap();
    if(s<0)
        cout<<"-1";
    if(kt())
    {
        euler(gt);
        if(kq.size()<n+1)
            cout<<"-1";
        else
        {
            for(int i=0; i<kq.size(); i++)
                cout<<kq[i]<<" ";
            cout<<endl;
        }
    }
    else
        cout<<"-1";
    return 0;
}
