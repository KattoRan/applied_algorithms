#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+7;
const int oo = 1e7+9;
int c[20][20], d[20];
int n,k,q;
int dp_s[N][15], dp_mask[N], dp[6][N], w[N];
void read(int &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while((c<'0'||c>'9')&&c!='-') c=getchar();
    if(c=='-')
    {
        c=getchar();
        tam=-1;
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}
// dp_s[i][j]: quãng đường nhỏ nhất ở trạng thái i (các bit 1 là số khách được giao hàng) và kết thúc tại khách thứ j
// dp_mask[i]: quãng đường nhỏ nhất ở trạng thái i// và quay về 0
// dp[k][i]: k xe đi được trạng thái i
int main()
{
    read(n); read(k); read(q);
    for (int i = 1; i <= n; i++) read(d[i]);
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++) read(c[i][j]);
    int m = (1<<n)-1;
    for (int i = 0; i <= m; i++)
    {
        dp_mask[i] = oo;
        if (i == 0) dp_mask[i] = 0;
        for (int j = 1; j <= n; j++)
        {
            dp_s[i][j] = oo;
            if((i>>(j-1))&1)
            {
                for (int e = 1; e <= n; e++)
                {
                    int m1 = i^(1<<(j-1));
                    if (m1 == 0) {dp_s[i][j] = c[0][j]; continue;}
                    if((i>>(e-1))&1 && e!=j) dp_s[i][j] = min(dp_s[i][j],dp_s[m1][e]+c[e][j]);
                }
            }
        }
        for (int j = 1; j <= n; j++)
            dp_mask[i] = min(dp_mask[i], dp_s[i][j]+c[j][0]);
    }
    w[0] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if ((i>>(j-1))&1)
                w[i]+=d[j];
    int res = oo;
    for (int i = 0; i <= m; i++) dp[0][i] = oo;
    dp[0][0]=0;
    for(int i = 1; i <= k; i++)
    {
        for (int j = 0; j<= m; j++)
        {
            dp[i][j] = oo;
            for (int e = 0; e <= m; e++)
                if((j&e) == e && w[e] <= q)
                {
                    dp[i][j] =min(dp[i][j], dp[i-1][e^j]+dp_mask[e]);
                }
        }
        res = min(res,dp[i][m]);

    }
    cout << res;

}
