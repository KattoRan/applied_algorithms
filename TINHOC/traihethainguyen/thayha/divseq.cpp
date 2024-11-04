#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int n,k;
int c[maxn],p[maxn];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("divseq.inp","r",stdin);
    freopen("divseq.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>c[i];
    p[1]=0;
    for(int i=2;i<=n;i++)
    {
        while(k>0&&c[i]!=c[k+1]) k=p[k];
        if(c[i]==c[k+1]) k++;
        p[i]=k;
    }
    cout<<n-p[n];
}
