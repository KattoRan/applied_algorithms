#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,a[N],k;
int l[N],b[N];
main()
{
     ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
    freopen("LISTB.inp","r",stdin);
    freopen("LISTB.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
        k=0;
    for(int i=1;i<=n;i++)
        if(a[i]%2==0)
    {
        int j=lower_bound(b+1,b+k+1,a[i])-b;
        if(j==k+1) k++;
        l[j]=i;
        b[j]=a[i];
    }
    cout<<k;
}
