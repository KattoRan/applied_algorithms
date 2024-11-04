#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int n,m,a[maxn];
bitset<maxn> f;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    f[0]=1;
    for(int i=1;i<=n;i++) f|=f<<a[i];
   // cout<<f;
}

4
11
2 4 6 8

