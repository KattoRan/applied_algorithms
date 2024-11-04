#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int N=1e3+1;
const int NN=1e4+1;
int a[N],n,res,m;
int l[NN];
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subseq1.inp","r",stdin);
    freopen("subseq1.out","w",stdout);
    cin>>n>>m;
    res=n;
    fu(i,1,n) cin>>a[i];
    l[0]=1;
    fu(i,1,n)
    fd(j,m,a[i])
    {
        if(l[j-a[i]]!=0&&l[j]==0)
            l[j]=l[j-a[i]]+1;
        else
            if(l[j-a[i]]!=0)
            l[j]=min(l[j-a[i]]+1,l[j]);
    }
    cout<<l[m]-1;

}
