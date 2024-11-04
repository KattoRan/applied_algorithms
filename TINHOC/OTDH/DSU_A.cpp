#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,m,cha[N];
int find1(int u)
{
    return (cha[u]<0)?u:cha[u]=find1(cha[u]);
}
void find2(int u,int v)
{
    u=find1(u);
    v=find1(v);
    if(u==v) return;
    if(cha[v]<cha[u]) swap(u,v);
    cha[u]+=cha[v];
    cha[v]=u;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("DSU_A.inp","r",stdin);
    freopen("DSU_A.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cha[i]=-1;
    while(m--)
    {
        int x,u,v;
        cin>>x>>u>>v;
        if(x==1) find2(u,v);
        else
            cout<<(find1(u)==find1(v))<<'\n';
    }
}
