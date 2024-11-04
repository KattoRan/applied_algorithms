#include<bits/stdc++.h>
using namespace std;
struct dt{ int z1,s1,m1,z2,s2,m2;};
int z,m,s,z0,m0,s0;
int res,d,n;
vector<dt> a;
void dfs(int z,int s,int m)
{
    if(z>=z0&&s>=s0&&m>=m0) res=min(res,d);
    else
        for(int i=0; i<=n-1; i++)
        {
            int u=a[i].z1;
            int v=a[i].s1;
            int t=a[i].m1;
            int u1=a[i].z2;
            int v1=a[i].s2;
            int t1=a[i].m2;
            if(z>=u&&s>=v&&m>=t&&z-u+u1<=4&&s-v+v1<=4&&m-t+t1<=4)
            {
                d++;
                dfs(z-u+u1,s-v+v1,m-t+t1);
                d--;
            }
        }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("collect.inp","r",stdin);
    freopen("collect.out","w",stdout);
    cin>>z>>s>>m>>z0>>s0>>m0;
    int zt1,st1,mt1,zt2,mt2,st2;
    while(cin>>zt1>>st1>>mt1>>zt2>>st2>>mt2)
    {
        n++;
        a.push_back({zt1,st1,mt1,zt2,st2,mt2});
    }
    d=0;
    res=1000007;
    dfs(z,s,m);
    cout<<res;
}
