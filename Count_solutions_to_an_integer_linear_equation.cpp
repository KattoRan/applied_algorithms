#include <bits/stdc++.h>
using namespace std;

const int N=1e6+7;
const int oo=1e6+7;

typedef long long ll;
typedef pair<int,int> ii;

template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-')
    {
        tam=-1;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}

int n, m;
int s[N], a[N];
long long dem = 0;
long long f = 0;
void Try(int i)
{
	int mm = m - f - (s[n]-s[i])/a[i];
	for (int j = 1; j <= mm; j++)
	{
		f += j*a[i];
		if (i == n){
			if (f == m) dem++;
		}
		else Try(i+1);
		f -= j*a[i];
	}
}

int main()
{
	read(n); read(m);
	for (int i = 1; i <= n; i++)
		read(a[i]), s[i] = s[i-1] + a[i];
	Try(1);
	cout << dem;

	return 0;
}