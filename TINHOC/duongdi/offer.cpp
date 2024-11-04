#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3;
const int oo=1e9+7;
int n,cx[maxn],k,res;
vector<int> a[maxn];
void dfs(int s)
{
    cx[s]=0;
    k++;
    for(int i=0;i<a[s].size();i++)
        if(cx[a[s][i]]) dfs(a[s][i]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("offer.inp","r",stdin);
    freopen("offer.out","w",stdout);
    cin>>n;
    int u,v;
    while(cin>>u>>v)
        a[u].push_back(v);
    res=oo;
    for(int i=1;i<=n;i++)
    {
        for(int v=1;v<=n;v++) cx[v]=1;
        k=0;
        dfs(i);
        res=min(res,k);
    }
    cout<<res;
}

