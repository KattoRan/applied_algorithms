#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int n,a[maxn],m;
int l,res;
long long t;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>m>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    res=n;
    for(int i=1; i<=n; i++)
    {
        t+=(long long)a[i];
        l=i;
        int l1=l;
        if(t>=m)
        {
            for(int j=i+1; j<=n; j++)
                if(t-(long long)a[j-l1]+(long long)a[j]<m)
                {
                    l=n;
                    break;
                }
            res=min(res,l);
        }
    }
    cout<<res;
}
