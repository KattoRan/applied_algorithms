#include<bits/stdc++.h>
#define task "demnt"
using namespace std;
int a,b,d;
bool ktr(int n)
{
    if(n<2) return false;
    if(n<4) return true;
    int m=sqrt(n);
    for(int i=2; i<=m; i++)
        if(n%i==0) return false;
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>a>>b;
    for(int i=a;i<=b;i++)
        if(ktr(i)) d++;
    cout<<d;
}
