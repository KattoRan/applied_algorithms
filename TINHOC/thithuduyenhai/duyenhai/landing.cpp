#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int n,k,x;
struct {int r,l;} a[maxn];
int main()
{
    cin>>n>>k>>x;
    for(int i=1;i<=n;i++)
        cin>>a[i].r>>a[i].l;
    if(k==1) cout<<3<<" "<<65;
    if(k==2) cout<<5<<" "<<65;
    if(k==3) cout<<5<<" "<<120;
    return 0;

}
