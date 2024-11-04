#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+1;
int n,res;
long long cost[maxn];
struct quanli
{
    int d;
    int c;
    int p;
};
quanli q[1001];
bool cmp(quanli i,quanli j)
{
    if(i.d==j.d)
        return i.c<j.c;
    return i.d<j.d;
}
void init()
{
      ios_base::sync_with_stdio(0);
      cin.tie(0);
      cout.tie(0);
      freopen("renting.INP","r",stdin);
      freopen("renting.OUT","w",stdout);
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>q[i].d>>q[i].c>>q[i].p;
    }
    sort(q+1,q+n+1,cmp);
}
void tinh()
{
    for(int i=1; i<=n; i++)
        cost[i]=q[i].p;
    for(int i=2; i<=n; i++)
        for(int j=i-1; j>=1; j--)
        {
            if(q[i].d>q[j].c)
                cost[i]=max(cost[j]+q[i].p,cost[i]);
        }
    res=cost[1];
    for(int i=2; i<=n; i++)
        if(cost[i]>res)
            res=cost[i];
}
int main()
{
    init();
    tinh();
    cout<<res;
    return 0;
}

