#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
using namespace std;
const int N=1e5+7;
struct node{int lazy;int val;} nut[4*N];
int n,m,q;
ll a[N];

void build(int x,int l,int r)
{
    if(l==r) nut[x].val=a[l];
    else
    {
        int mid=(l+r)/2;
        build(2*x,l,mid);
        build(2*x+1,mid+1,r);
        nut[x].val=max(nut[2*x].val,nut[2*x+1].val);
    }
}
void down(int x)
{
    int st=nut[x].lazy;
    nut[x*2].lazy+=st;
    nut[x*2].val+=st;
    nut[x*2+1].lazy+=st;
    nut[x*2+1].val+=st;
    nut[x].lazy=0;
}
void lazy_up(int x,int l,int r,int u,int v,int val)
{
    if(v<l||r<u) return;
    if(u<=l&&r<=v)
    {
        nut[x].val+=val;
        nut[x].lazy+=val;
        return;
    }
    int mid=(l+r)/2;
    down(x);
    lazy_up(x*2,l,mid,u,v,val);
    lazy_up(x*2+1,mid+1,r,u,v,val);
    nut[x].val=max(nut[x*2].val,nut[x*2+1].val);
}

ll get(int x,int l,int r,int qi,int qj)
{
    if(qj<l||r<qi)return 0;
    if(qi<=l&&r<=qj) return nut[x].val;
    int mid=(l+r)/2;
    down(x);
    return max(get(2*x,l,mid,qi,qj),get(2*x+1,mid+1,r,qi,qj));
}

int main()
{
   /* ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("findmax.inp","r",stdin);
    freopen("findmax.out","w",stdout);*/
    cin>>n>>m;
    fu(i,1,n) cin>>a[i];
    build(1,1,n);
    while(m>0)
    {
        m--;
        int u,v,k;
        cin>>u>>v>>k;
        lazy_up(1,1,n,u,v,k);
    }
    cin>>q;
    fu(i,1,q)
    {
        int u,v;
        cin>>u>>v;
        cout<<get(1,1,n,u,v)<<'\n';
    }
}
