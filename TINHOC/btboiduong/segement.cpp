#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int n,a[maxn],s[maxn];
int main()
{
    cin>>n;
    for(it i=1;i<=n;i++) cin>>a[i];
    s[0]=0;
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    sum=s[n];

}
