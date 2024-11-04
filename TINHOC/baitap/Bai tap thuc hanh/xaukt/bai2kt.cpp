#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+1;
long long a[MAXN],n,k,d;
int i;
int main()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=k;i++) if(a[i]%2==0) d++;
    i=2;
    while(k-1+i<=n)
    {
        if(a[k-1+i]%2==0&&a[i-1]%2!=0) d++;
        if(a[k-1+i]%2!=0&&a[i-1]%2==0) d--;
        i++;
        if(k-1+i==n) break;
    }
    cout<<d;
    return 0;
}
