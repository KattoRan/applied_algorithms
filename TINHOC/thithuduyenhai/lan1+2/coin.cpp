#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
const int maxn=1e6+7;
int k,n,f[maxn],g[maxn];
int res;
long long tmp;
string s;
map<long long, int> ma;
int main()
{
    cin>>n>>k;
    cin>>s;
    s="="+s;
    for(int i=1; i<=n; i++)
    {
         if(s[i]=='O') f[i]=f[i-1]+1;
         else f[i]=f[i-1];
         if(s[i]=='R') g[i]=g[i-1]+1;
         else g[i]=g[i-1];
    }
    ma[0]=0;
    for(int i=1; i<=n; i++)
    {
        tmp=f[i]-k*g[i];
        if (ma.find(tmp) != ma.end()) res = max(res, i - ma[tmp]);
        else ma[tmp]=i;
    }
    cout<<res;
    return 0;
}
