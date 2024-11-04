#include<bits/stdc++.h>
#define ii pair<int,int>
using namespace std;

const int N=20007;
const int oo=1e9+7;

int n,p,q,u,v,d[N],trc[N],l,r,dem;
vector<ii> a[N];
vector<int>kq;
bool ok=0;

void dij(int s)
{
    for(int i=0;i<=n;i++) d[i]=oo;
    priority_queue<ii,vector<ii>,greater<ii> >q;
    d[s]=0;
    q.push({0,s});
    while(q.size()){
        int u=q.top().second;
        int du=q.top().first;
        q.pop();

        if(du!=d[u]) continue;

        for(int i=0;i<a[u].size();i++){
            int v=a[u][i].first;
            int w=a[u][i].second;
            if(d[v]>d[u]+w){
                d[v]=d[u]+w;
                q.push({d[v],v});
                trc[v]=u;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("disk.INP","r",stdin);
    freopen("disk.OUT","w",stdout);
    cin>>n>>p>>q>>u>>v;
    for(int i=0;i<=n;i++)
    {
        if(i+p<=n) a[i].push_back({i+p,1});
        if(i-q>=0) a[i].push_back({i-q,1});
    }
    dij(u);
    int j=v;
    do
    {
        kq.push_back(j);
        j=trc[j];
    }
    while(j!=u);
    if(d[v]==oo)
    {
        cout<<-1;
        return 0;
    }
    cout<<d[v]<<endl<<" ";
    dem=u;
    while(kq.size())
    {
        int x=kq.back();
        if(dem>x) l++,ok=0;
        else r++,ok=1;
        if(l>0&&ok==1)
        {
            cout<<"L"<<l<<" ";
            l=0;
        }
        if(r>0&&ok==0)
        {
            cout<<"T"<<r<<" ";
            r=0;
        }
        dem=x;
        kq.pop_back();
    }
    if(l>0)
        {
            cout<<"L"<<l<<" ";
            l=0;
        }
        if(r>0)
        {
            cout<<"T"<<r<<" ";
            r=0;
        }
}
