#include<bits/stdc++.h>
#define fort(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;

using namespace std;
const int maxn=1e4+7;
struct node{int lazy,value;}nodes[maxn];

int leaf[maxn];
int n,m;
vector<int> a,sum;

void down(int id)
{
    int t=nodes[id].lazy;
    nodes[id*2].lazy+=t;
    nodes[id*2].value+=t;
    nodes[id*2+1].lazy+=t;
    nodes[id*2+1].value+=t;
    nodes[id].lazy=0;
}
void update(int id,int l,int r,int u,int v,int w)
{
    if(u>r||v<l) return;
    if(u<=l&&r<=v) {nodes[id].lazy+=w;nodes[id].value+=w;return;}
    int mid=(l+r)/2;
    down(id);
    update(id*2,l,mid,u,v,w);
    update(id*2+1,mid+1,r,u,v,w);
    nodes[id].value=max(nodes[id*2].value,nodes[id*2+1].value);
}
int request(int id,int l,int r,int qi,int qj)
{
    if(qi>r||qj<l)return 0;
    if(qi<=l&&r<=qj) return nodes[id].value;
    int mid=(l+r)/2;
    down(id);
    return max(request(2*id,l,mid,qi,qj),request(2*id+1,mid+1,r,qi,qj));
}
main()
{
    cin>>n>>m;
    fort(i,1,m)
    {
        int k;
        cin>>k;
        if(k==0) {int u,v,w;
                  cin>>u>>v>>w;
                  update(1,1,n,u,v,w);}
        if(k==1) {int qi,qj;
                  cin>>qi>>qj;
                  cout<<request(1,1,n,qi,qj);
        }
    }
    return 0;
}

