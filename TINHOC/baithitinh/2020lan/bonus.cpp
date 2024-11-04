#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e6+7;
int n,k,a[N];
long long f[N],s[N],b[N],dd[N];
deque<int> q;
vector<int> c;
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
int main()
{
    #define name "bonus"
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen(name".inp","r",stdin);
	//freopen(name".out","w",stdout);
    read(n);
    read(k);
    fu(i,1,n) read(a[i]);
    s[0]=0;f[0]=0;
    fu(i,1,n) s[i]=s[i-1]+a[i];
    fu(i,1,k-1)
    {
        f[i]=s[i];
        b[i]=f[i-1]-s[i];
        while(q.size()&&b[q.back()]<=b[i]) q.pop_back();
        q.push_back(i);
    }
    fu(i,k,n)
    {
        while(q.front()<i-k+1) q.pop_front();
        b[i]=f[i-1]-s[i];
        while(q.size()&&b[q.back()]<=b[i]) q.pop_back();
        q.push_back(i);
        f[i]=b[q.front()]+s[i];
        cout<<q.front()<<'\n';
    }
    for(int i=1;i<=n;i++) cout<<b[i]<<" "<<f[i]<<'\n';
}
