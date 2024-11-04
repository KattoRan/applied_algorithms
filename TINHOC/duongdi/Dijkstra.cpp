#include <bits/stdc++.h>
using namespace std;
const int maxn=1e4+1;
const int maxm=1e5+1;
const int oo=1e9+1;
int trc[maxn],s,t,n,m,d[maxn],kq[maxn],res=0;
bool cx[maxn];
typedef pair<int,int> ii;
vector <ii> a[maxn];
void nhap()
{
    cin>>n>>m>>s>>t;
    for(int i=1; i<=m; i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        a[u].push_back({v,w});
    }
    for(int i=0; i<=n; i++)d[i]=oo,cx[i]=true;
    d[s]=0;
    trc[s]=0;
}
void Dijkstra(int s)
 {
     int u;
     while(true)
     {
         u=0;
         for(int v=1;v<=n;v++)
            if(cx[v]&&d[v]<d[u]) u=v;
         if(u==0) break;
         cx[u]=false;
         for(int i=0;i<a[u].size();i++){
            int v=a[u][i].first;
            int w=a[u][i].second;
            if(cx[v]&&d[u]+w<d[v]){
                d[v]=d[u]+w;
                trc[v]=u;
            }
         }
     }
 }
 int main()
 {
        nhap();
    Dijkstra(s);
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
