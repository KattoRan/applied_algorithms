// Cat \\
||*---*||
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

const int N=1e6+7;

typedef long long ll;
typedef pair<int,int> ii;

string s;
string p[N];
int n;
map<string,int> dem;
int f[N];

template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-')
        c=getchar();
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

void ent()
{
    cin>>n;
    cin>>s;
    fu(i,1,n)
    cin>>p[i],dem[p[i]]=1;

}

void solve()
{
    int m=s.size();
    int x=p[1].size();
    int d,res=0;
    fu(i,0,m-1)
    {
        d=0;
        int kc=i-x;
        int j=s.find(p[1],i);
        while(j==kc+x)
        {
            kc=j;
            j=s.find(p[1],kc+x);
            d+=x;
        }
        res=max(res,d);
    }
    cout<<res;
}
void solve2()
{
    int m=s.size();
    int res=0;
    fu(i,0,m-1)
    {
        string s1="";
        fd(j,i,0)
        {
            s1=s[j]+s1;
            if(dem[s1]==1)
                f[i]=max(f[i],f[j-1]+i-j+1);
        }
        res=max(res,f[i]);
    }
    cout<<res;
}
int vet[N],kt[N][4],xet[N];
void solve3()
{
    vet['a']=0;vet['b']=1;vet['c']=2;vet['h']=3;
    cin>>n;cin>>s;int m=s.size();s=" "+s;
    int sl=1;
    for(int i=1;i<=n;i++)
        {
            string p;
            cin>>p;
            int k=1;
            for(int j=0;j<p.size();j++)
            {
                if(kt[k][vet[p[j]]]==0) kt[k][vet[p[j]]]= ++sl;
                k=kt[k][vet[p[j]]];
            }
            xet[k]=1;
        }

	for(int i=0;i<m;++i)
	{
		int gt=1;
		for(int j=i+1;j<=m;++j)
		{
			gt=kt[gt][vet[s[j]]];
			if(gt==0) break;

			if(xet[gt]) f[j]=max(f[j],f[i]+j-i);
		}
	}
	cout<<*max_element(f,f+m+1);
}
catlan()
{
#define name "laugh"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    if(n==1||n==2)
    {ent();
    if(n==1)
        solve();
    else solve2();}
    else solve3();
}
