#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define catlan main
#define bit(X,i) ((X>>i)&1)
#define on(X,i) (X|(1<<i))
#define off(X,i) (X^(1<<i))
#define dembit(X) __builtin_popcount(X)
using namespace std;

const int N = 1e3 + 7;
const int M = 1e6 + 7;
const int oo = 1e6+7;

typedef long long ll;
typedef pair<int,int> ii;

template <typename T> inline void read(T &x)
{
    x = 0;
    char c = getchar();
    int sign = 1;
    while(!isdigit(c) && c != '-') c = getchar();
    if(c == '-')
    {
        sign = -1;
        c = getchar();
    }
    while(isdigit(c))
    {
        x = x * 10 + (c - '0');
        c = getchar();
    }
    x *= sign;
}
int dx[16], n, k;
int f = 0, load = 0, res = oo;
int c[31][31];
int x[31];
int cmin;
bool check(int v)
{
	if (dx[v]==1) return false;
	if (v > n)
		{if (dx[v-n] == 0) return false;}
	else
        if (load+1 > k) return false;
	return true;
}
void update()
{
	if (c[x[2*n]][0] + f < res) res = c[x[2*n]][0] + f;
}
void Try(int i)
{
	for (int j = 1; j <= 2*n; j++)
		if(check(j))
	{
		x[i] = j;
		dx[j] = 1;
		f += c[x[i-1]][j];
		if (j > n) load-=1;
		else load+=1;

		if (i == 2*n) update();
		else
            {
                //cout << i << " " << j <<endl;
                //cout << "f: " << f << " res: " << res;
                if (f + (2*n - i + 1)*cmin < res)
                    Try(i+1);
            }
        if (j > n) load+=1;
		else load-=1;
		dx[j] = 0;
		f -= c[x[i-1]][j];
	}
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cmin = oo;
    cin >> n >> k;
    for (int i = 0; i <= 2*n; i++)
        for (int j = 0; j <= 2*n; j++)
    {
        cin >> c[i][j];
        if (i!=j) cmin = min(cmin,c[i][j]);
    }
    Try(1);
    cout << res;
    return 0;
}
