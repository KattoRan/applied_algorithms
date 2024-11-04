#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
struct ds{int u,v,c;}m1[N];
int p[N],res[N],cha[N];
int m,n;
int find1(int u)
{
    return (cha[u]<0)?u:cha[u]=find1(cha[u]);
}
void merge2(int u,int v,int c)
{
    u=find1(u);
    v=find1(v);
    if(u==v) return;
    if(cha[v]<cha[u]) swap(u,v);
    cha[u]+=cha[v];
    cha[v]=u;
    int k=abs(cha[u]);
    res[k]=max(c,res[k]);
}
bool cmp(ds a,ds b)
{
    return a.c>b.c;
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("DSU_B.inp","r",stdin);
    freopen("DSU_B.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cha[i]=-1,res[i]=-1;
    for(int i=1;i<=n;i++) cin>>p[i],res[1]=max(res[1],p[i]);
    for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        int tg=min(p[u],p[v]);
        m1[i]={u,v,tg};
    }
    sort(m1+1,m1+m+1,cmp);
    for(int i=1;i<=m;i++)
        merge2(m1[i].u,m1[i].v,m1[i].c);
    int tmp;
    for(int i=n;i>=1;i--)
    {
        if(res[i]!=-1) tmp=res[i];
        else res[i]=tmp;
    }
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
}

