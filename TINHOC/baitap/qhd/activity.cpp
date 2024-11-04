#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
const int oo=1e9+7;
int n,a[maxn],b[maxn],k,kq[maxn];
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("activity.INP","r",stdin);
    freopen("activity.OUT","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>q[i].s>>q[i].f;
        q[i].vt=i;
        b[i]=+oo;
    }
    sort(q+1,q+n+1,cmp);
    k=0;
}
void tinh()
{
    for(int i=1;i<=n;i++)
    {
        int j=upper_bound(b+1,b+k+1,q[i].s)-b;
        if(j==k+1) k++;
        if(q[i].f<b[j])
        {
            b[j]=q[i].f;
            kq[j]=q[i].vt;
        }
    }
}
int main()
{
    init();
    tinh();
    cout<<k<<endl;
    for(int i=1;i<=k;i++)
        cout<<kq[i]<<endl;
    return 0;
}

