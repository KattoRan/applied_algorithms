#include<bits/stdc++.h>
using namespace std;
const int oo=1e9+1;
const int maxn=1e6+1;
int n,t[maxn],nv[maxn],num,deg[maxn];
int m[maxn],s[maxn];
long long d[maxn];
bool cx[maxn];
vector<int> ra[maxn],vao[maxn];
void numbering(){
    for(int i=0; i<=n+1; i++)
        deg[i]=0;
    for(int u=0; u<=n+1; u++)
        for(int i=0; i<ra[u].size(); i++)
        {
            int v=ra[u][i];
            deg[v]++;
        }
   queue<int> q;
   int num;
   for(int i=0;i<=n+1;i++)
      if(deg[i]==0) q.push(i);
   num=-1;
   while(!q.empty())
   {
       int u=q.front();q.pop();
       num++;
       nv[num]=u;
       for(int i=0;i<ra[u].size();i++)
       {
           int v=ra[u][i];
           deg[v]--;
           if(deg[v]==0) q.push(v);
       }
   }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("pert.inp","r",stdin);
    freopen("pert.out","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++){
        int k; cin>>k;
        for(int j=1; j<=k; j++){
            int u;
            cin>>u;
            ra[u].push_back(i);
            vao[i].push_back(u);}
        cin>>t[i];}
    t[0]=0;
    t[n+1]=0;
    for(int u=1; u<=n; u++){
        if(vao[u].empty())
            {ra[0].push_back(u);
            vao[u].push_back(0);}
        if(ra[u].empty())
             {vao[n+1].push_back(u);
             ra[u].push_back(n+1);}}
    numbering();
    for(int i=0;i<=n+1;i++)
    {
        int u=nv[i];
        for(int v=0;v<ra[u].size();v++)
            if(d[ra[u][v]]<d[u]+t[u]) d[ra[u][v]]=d[u]+t[u];
    }
    int h=d[n+1];
    m[n+1]=h;
    for(int u=n;u>=1;u--){m[u]=oo;
        for(int j=0;j<ra[u].size();j++)
    {
        int v=ra[u][j];
        m[u]=min(m[u],m[v]-t[v]);
    }
    }
    for(int i=0;i<ra[0].size();i++) s[i]=0;
    for(int v=1;v<=n;v++){s[v]==-oo;
        for(int i=0;i<vao[v].size();i++)
        {int u=vao[v][i];
        s[v]=max(s[v],s[u]+t[u]);}}
    cout<<h<<'\n';
    for(int i=1;i<=n;i++) cout<<s[i]<<" "<<m[i]<<'\n';
}

