#include<bits/stdc++.h>
using namespace std;
int t;
int l[1001],r[1001];
long long lcm;
int UCLN(int a, int b){
    if(a==b) return a;
    if(a>b)
        UCLN(a-b,b);
    else
        UCLN(a,b-a);
}
int BCNN(int a, int b){
    return (a*b/UCLN(a,b) );
}
int main()
{
    cin>>t;
    for(int i=1;i<=t;i++) cin>>l[i]>>r[i];
    for(int k=1;k<=t;k++)
        for(int i=l[k];i<=r[k]-1;i++)
            for(int j=i+1;j<=r[k];j++)
            if(BCNN(i,j)>=l[k]&&BCNN(i,j)<=r[k]) cout<<i<<" "<<j<<'\n';
    return 0;
}
