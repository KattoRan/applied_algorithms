#include<bits/stdc++.h>
#define fu(i,d,c) for(int i=d;i<=c;i++)
using namespace std;
typedef long long ll;
const int maxn=1e6+3;
const int oo=1e9+1;
int n,a[maxn],k,h;
ll dem,res,s[maxn];
void read(int &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    if((c<'0'||c>'9')&&c!='-') return;
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
void enter()
{
	read(n);
	read(k);
	read(h);
	fu(i,1,n)
	read(a[i]);
}

void solve()
{
    dem=ll(h*2)/k+1;
	fu(i,1,n)
	s[i]=s[i-1]+(ll)a[i];
	if(dem>=n)
        cout<<s[n];
    else
    {
        fu(i,1,n-dem+1)
        {
            res=max(res,s[i+dem-1]-s[i-1]);
        }
        cout<<res;
    }
}

int main()
{
        #define name "lychee"
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(name".inp","r",stdin);
	freopen(name".out","w",stdout);
	enter();
	solve();
	return 0;
}
