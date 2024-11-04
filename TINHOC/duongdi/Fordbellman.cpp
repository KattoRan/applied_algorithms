#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+1;
const int maxm=1e5+1;
const int oo=1e9+1;
struct ii{int u,v,w;};
int trc[maxn],s,t,n,m,d[maxn],kq[maxn],res=0;
vector <ii > a;
void nhap()
{
    cin>>n>>m>>s>>t;
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a.push_back({u,v,w});
    }
    for(int i=1; i<=n; i++)d[i]=oo;
    d[s]=0;
    trc[s]=0;
}
void bellman()
{
   bool stop;
   int u,v,w;
   for(int k=1;k<=n;k++){
    stop=true;
    for(int i=0;i<a.size();i++){
        u=a[i].u;
        v=a[i].v;
        w=a[i].w;
        if(d[u]<oo&&d[u]+w<d[v]){
            d[v]=d[u]+w;
            trc[v]=u;
            stop=false;
        }
    }
    if(stop) break;
   }
}
int main()
{
    nhap();
    bellman();
    if(d[t]==oo) cout<<"-1";
    else{
    int i=t;
    while(i!=0)
    {
        res++;
        kq[res]=i;
        i=trc[i];
    }
    cout<<d[t]<<'\n';
    for(int i=res; i>=1; i--)cout<<kq[i]<<" ";}
    return 0;
}
