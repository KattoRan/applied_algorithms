#include<bits/stdc++.h>
using namespace std;
const int maxn=40;
const int maxm=1e8+7;
int m,n,l[maxm];
int w[maxn],v[maxn];
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>w[i]>>v[i];
    for(int j=1;j<=m;j++) l[j]=0;
    for(int i=1;i<=n;i++)
        for(int j=m;j>=1;j--)
    {
        if(j-w[i]>=0)
            l[j]=max(l[j],v[i]+l[j-w[i]]);
    }
    cout<<l[m];
}

