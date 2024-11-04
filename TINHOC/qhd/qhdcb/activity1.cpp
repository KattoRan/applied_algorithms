#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int n,tr[maxn],l[maxn],res,kq[maxn];
struct quanli
{
    int s,f,vt;
};
quanli q[maxn];
bool cmp(quanli i,quanli j)
{
    if(i.s==j.s)
        return i.f<j.f;
    return i.s<j.s;
}
void init()
{
   /* ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("activity.INP","r",stdin);
    freopen("activity.OUT","w",stdout);*/
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>q[i].s>>q[i].f;
        q[i].vt=i;
    }
    sort(q+1,q+n+1,cmp);
}
void tinh()
{
    l[0]=0;
    int jo;
    for(int i=1; i<=n; i++)
    {
        jo=0;
        for(int j=i-1; j>=1; j--)
            if(q[j].f<=q[i].s&&l[j]>l[jo])
                jo=j;
        l[i]=l[jo]+1;
        tr[i]=jo;
    }
    int io;
    io=1;
    for(int i=2; i<=n; i++)
        if(l[i]>l[io])
            io=i;
    res=l[io];
    for(int i=res; i>=1; i--)
        kq[i]=io,io=tr[io];
}
int main()
{
    init();
    tinh();
    cout<<res<<'\n';
    for(int i=1; i<=res; i++)
        cout<<q[kq[i]].vt<<'\n';
    return 0;
}
