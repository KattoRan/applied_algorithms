#include<bits/stdc++.h>
using namespace std;
const int oo=1e7+7;
const int maxn=1e3+1;
int n;
int l[maxn],f[25][maxn],cs[maxn];
int a[25];
int res;
map <int,int> ma,mares;
void timkq()
{
#include<bits/stdc++.h>
using namespace std;
const int oo=1e7+7;
const int maxn=670;
int n;
int l[maxn],f[25][maxn],cs[maxn];
int a[25];

int dp[maxn], trace[maxn];
int cnt[25];

void debug_out() { cerr << '\n'; }
template <typename Head, typename ...Tail>
void debug_out(Head H, Tail ...T)
{
    cerr << " " << H;
    debug_out(T...);
}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(_VA_ARGS_)

void GetAns(int coin)
{
    if (!coin) return;

    //debug(coin, dp[coin]);

    ++cnt[trace[coin]];
    GetAns(coin - a[trace[coin]]);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    //freopen("coin.inp","r",stdin);
    //freopen("coin.out","w",stdout);
    cin>>n;

    for(int i=1; i<=20; i++)
        a[i]=i*i;

    for(int i=0; i<=20; i++)
    {
        f[i][0]=0;
        for(int j=1; j<=n; j++)
            f[i][j]=oo;
    }

    l[0]=1;
    for(int i=1; i<=20; i++)
        for(int j=n; j>=0; j--) if(a[i]<=j)
            for(int k=1;k*a[i]<=j;k++)
                l[j]+=l[j-a[i]*k];
    cout<<l[n]<<'\n';

    /*
    for(int j=1; j<=n; j++)
        for(int i=1; i<=20; i++)
        {
            if(a[i]>j)
                f[i][j]=f[i-1][j];
            else
                f[i][j]=min(f[i-1][j],1+f[i][j-a[i]]);
        }
    cout<<f[20][n]<<'\n';
    int i,j;
    i=20;j=n;
    while(i>=1&&j>=1)
    {
        if(f[i][j]==f[i-1][j]) cs[i]=0;
        else cs[i]++,j-=a[i];
        i--;
    }
    for(int i=20;i>=1;i--) if(cs[i])
        cout<<cs[i]<<" "<<i<<'\n';
    */

    for (int s = 1; s <= n; ++s)
        dp[s] = oo;
    dp[0] = 0;

    for (int s = 1; s <= n; ++s)
    {
        int mi = 0;
        for (int i = 1; i <= 20; ++i) if (s >= a[i])
        {
            if (!mi || dp[s - a[i]] < dp[s - a[mi]])
                mi = i;
        }

        if (mi)
        {
            dp[s] = dp[s - a[mi]] + 1;
            trace[s] = mi;
        }
    }
    cout << dp[n] << '\n';
    GetAns(n);
    for (int i = 20; i > 0; --i)
    {
        if (cnt[i])
            cout << cnt[i] << " " << i << '\n';
    }

    return 0;
}
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("coin.inp","r",stdin);
    //freopen("coin.out","w",stdout);
    cin>>n;
    for(int i=1; i<=20; i++)
        a[i]=i*i;
    for(int i=0; i<=20; i++)
        f[i][0]=0;
    for(int j=1; j<=n; j++)
        f[0][j]=oo;
    l[0]=1;
    for(int i=1; i<=20; i++)
        for(int j=n; j>=0; j--)
        if(a[i]<=j)
            for(int k=1;k*a[i]<=j;k++)
            l[j]+=l[j-a[i]*k];
    cout<<l[n]<<'\n';
    for(int i=1; i<=20; i++)
        for(int j=1; j<=n; j++)
        {
            if(a[i]>j)
                f[i][j]=f[i-1][j];
            else
                f[i][j]=min(f[i-1][j],1+f[i][j-a[i]]);
        }
    cout<<f[20][n]<<'\n';
    /*int i=20;
    while(a[i]<=n&&i>=1)
    {
       ma.clear();
       int j=i;
       int dem=0;
       while(a[j]<=n)
       {
           n-=a[j];
           dem++;
           ma[j]++;
       }
       i--;
       if(dem<res) mares=ma,res=dem;
    }
    for(int i=20;i>=1;i--)
        if(mares[i])
        cout<<mares[i]<<" "<<i<<'\n';*/
    timkq();
}
