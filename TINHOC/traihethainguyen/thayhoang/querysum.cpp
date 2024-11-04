#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int n,m;
long long tree[maxn];
int salary[maxn];
void increase(int x,int delta)
{
    for(;x<=n;x+=x&-x)
        tree[x]+=delta;
}
long long query1(int x)
{
    long long res=0;
    for(;x>0;x&=x-1) res=max(tree[x],res);
    return res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
  //  freopen("querysum.inp","r",stdin);
   // freopen("querysum.out","w",stdout);
    cin>>n>>m;
    fill(salary+1,salary+n+1,0LL);
    fill(tree+1,tree+n+1,0LL);
    while(m-->0)
    {
        char s;
        int i,j;
        cin>>s>>i>>j;
        if(s=='S') increase(i,j-salary[i]),salary[i]=j;
        if(s=='Q') cout<<query1(j)-query1(i-1)<<'\n';
    }
}
