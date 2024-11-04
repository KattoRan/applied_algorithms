#include<bits/stdc++.h>
#define up(i,d,c) for(int i=d;i<=c;i++)
using namespace std;
const int maxn=1e3+3;
const int oo=1e9+1;
string s,sa;
int d1,d2,l[maxn][maxn],n,m,io,jo,f[maxn][maxn];
void nhap()
{
	getline(cin,s);
	n=s.size();
	s="+"+s;
}

void xuli()
{
	up(i,1,n) l[i][i]=1;
    up(i,1,n-1) if(s[i]==s[i+1]) l[i][i+1]=1;
    up(j,3,n)
    up(i,1,j-2)
    {
        if(s[i]==s[j])l[i][j]=l[i+1][j-1];
        else l[i][j]=0;
    }
    d1=-oo;
    up(i,1,n)
    up(j,i,n)
    if(l[i][j]&&j-i+1>d1)
    {
        d1=j-i+1;
        io=i;
        jo=j;
    }
    cout<<d1<<endl;

	up(i,1,n) f[i][i]=1;
    for(int j=2;j<=n;j++)
    for(int i=j-1;i>=1;i--)
    {
        if(s[i]==s[j])f[i][j]=f[i+1][j-1]+2;
        else f[i][j]=max(f[i][j-1],f[i+1][j]);
    }
    cout<<f[1][n]<<" ";
}

int main()
{
    #define name "substr"
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(name".inp","r",stdin);
	freopen(name".out","w",stdout);
	nhap();
	xuli();
	return 0;
}
