#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define task "a"
using namespace std;
const int M=1e3+7;
const int N=1e6+7;
const int oo=1e9+7;
typedef long long ll;
int n,m;
int a[M],b[N],kq[M];
int f[M][M];
int dp[M][M];
vector<int> mini[M];

int Find(int i,int b)
{
    int j=upper_bound(mini[i].begin(),mini[i].end(),b)-mini[i].begin();
    return j;
}

void sub2()
{
    fu(i,1,m)
    mini[i].push_back(0);
    fu(i,1,m)
    fu(j,1,n)
    {
        if(a[i]==b[j]) mini[i].push_back(j);
    }
    fu(i,1,m)
    fu(j,i+1,m) dp[i][j]=oo;
    fu(i,1,m) dp[i][0]=1;
    fu(i,1,m)
    fu(k,1,i)
    {
        dp[i][k]=dp[i-1][k];
        int j=Find(i,f[i-1][k-1]);
        if(j==-1) continue;
        f[i][k]=min(f[i][k],j);
    }
    fu(i,1,m)
    {fu(k,1,i) cout<<f[i][k]<<" ";
    cout<<endl;}
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp","r",stdin);
    // freopen(task".out","w",stdout);
    cin>>m>>n;
    fu(i,1,m) cin>>a[i];
    fu(i,1,n) cin>>b[i];
    /*    if(n<=M)
            sub1();
        else*/
    sub2();
}
