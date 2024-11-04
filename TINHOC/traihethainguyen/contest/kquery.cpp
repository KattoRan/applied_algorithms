#include<bits/stdc++.h>
#define fort(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;
const int maxn=3*1e4+7;

using namespace std;

struct query{int k,l,r,ae;};
struct dc{int w,x;} dcs[maxn];
int n,m,id[maxn],a[maxn],b[maxn];
int st[maxn*4],res[maxn];
query q[200000];
bool cmp1(query a,query b)
{
    return a.k<b.k;
}
bool cmp2(dc a,dc b)
{
    return a.w<b.w;
}
void build(int x,int l,int r)
{
    if(l==r) st[x]=1;
    else
    {
        int mid = (l+r)/2;
        build(2*x,l,mid);
        build(2*x+1,mid+1,r);
        st[x]=st[x*2]+st[x*2+1];
    }
}
void update(int id,int l,int r,int u)
{
    if(u<l||r<u) return;
    if(l==r) {st[id]=0;return;}
    int mid=(l+r)/2;
    update(id*2,l,mid,u);
    update(id*2+1,mid+1,r,u);
    st[id]=st[id*2]+st[id*2+1];
}
int request(int id,int l,int r,int u,int v)
{
    if(u>r||v<l)return 0;
    if(u<=l&&r<=v) return st[id];
    int mid=(l+r)/2;
    return request(2*id,l,mid,u,v)+request(2*id+1,mid+1,r,u,v) ;
}
main()
{
    cin>>n;
    fort(i,1,n)cin>>a[i],dcs[i].w=a[i],dcs[i].x=i;
    sort(dcs+1,dcs+n+1,cmp2);
    fort(i,1,n) id[i]=dcs[i].x;
    int p;
    cin>>p;
    fort(i,1,p)
    cin>>q[i].l>>q[i].r>>q[i].k,q[i].ae=i;
    sort(q+1,q+p+1,cmp1);
    build(1,1,n);
    fort(i,1,p)
    {
        int j=1;
        while(a[id[j]]<=q[i].k)
        {
            b[id[j]]=0;
            update(1,1,n,id[j]);
            j++;
        }
        res[q[i].ae]=request(1,1,n,q[i].l,q[i].r);
    }
    fort(i,1,p) cout<<res[i]<<'\n';
    return 0;
}
