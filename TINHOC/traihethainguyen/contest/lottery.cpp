#include<bits/stdc++.h>
#define task "lottery"
using namespace std;
const int maxn=1e6+7;
int n,k,d,res;
int p[maxn];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>n>>k;
    for(int i=1; i<=n; i++)
        cin>>p[i];
    int a,b;
    cin>>a>>b;
     d=0;res=0;
    for(int i=a; i<=b; i++)
    {
        d=0;
        for(int j=1; j<=n; j++)
            if(i%p[j]==0) d++;
        if(d==k) res++;
    }
    cout<<res;
    return 0;

}
