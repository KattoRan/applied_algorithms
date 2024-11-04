#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
long long n,a[maxn],m1,m2,m3,res;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        m3=m1;
        if(m1<m2+a[i])m1=m2+a[i];
        if(m2<m3-a[i])m2=m3-a[i];
    }
    res=max(res,max(m1,m2));
    cout<<res;
}
