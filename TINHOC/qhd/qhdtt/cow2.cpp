#include<bits/stdc++.h>
#define task "cow2"
using namespace std;
int m,n,t;
long long res;
long long f[31][(1<<6)+1];
int getbit(int x,int k)
{
    return (x>>k)&1;
}
int ok(int x,int y)
{
    for(int i=1; i<m; i++)
    {
        if(getbit(x,i)&getbit(x,i-1)&getbit(y,i)&getbit(y,i-1))
            return 0;
        if(getbit(x,i)==0&&getbit(x,i-1)==0&&getbit(y,i)==0&&getbit(y,i-1)==0)
            return 0;
    }
    return 1;
}
void xuli(int m,int n)
{
    for(int x=0; x<(1<<m); x++)
        f[1][x]=1;
    for(int i=2; i<=n; i++)
        for(int x=0; x<(1<<m); x++)
            for(int y=0; y<(1<<m); y++)
                if(ok(x,y))
                    f[i][x]+=f[i-1][y];
    res=0;
    for(int x=0; x<(1<<m); x++)
        res+=f[n][x];
    cout<<res<<'\n';
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    cin>>t;
    while(t--)
    {
        int a,b;
        cin>>a>>b;
        m=min(a,b);
        n=max(a,b);
        memset(f,0,sizeof f);
        xuli(m,n);
    }
    return 0;
}
