#include<bits/stdc++.h>
#define f first
#define s second
using namespace std;
const int mn=1e6+7;
pair<int,int> dt[mn];
int s[mn],m,n,p[mn],q[mn];
double x[mn];

bool ok(int i)
{
    int u;
    u=s[m];
    if(dt[u].f==dt[i].f)return 0;
    if(m==1)return 1;
    double xM=1.0*(dt[u].s-dt[i].s)/(dt[i].f-dt[u].f);
    u=s[m-1];
    double xN=1.0*(dt[u].s-dt[i].s)/(dt[i].f-dt[u].f);
    return (xM>xN);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("cmax.inp","r",stdin);
    freopen("cmax.out","w",stdout);
        cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>dt[i].f>>dt[i].s;
    }
    sort(dt+1,dt+n+1);
    for(int i=1;i<=n;++i)
    {
        while(m>0&&!ok(i))--m;
        s[++m]=i;
    }
    p[0]=dt[s[1]].f;
    q[0]=dt[s[1]].s;
    x[0]=-1e10+1;
    for(int i=1;i<m;++i)
    {
        x[i]=1.0*(dt[s[i]].s-dt[s[i+1]].s)/(dt[s[i+1]].f-dt[s[i]].f);
        p[i]=dt[s[i+1]].f;
        q[i]=dt[s[i+1]].s;
    }
    x[m]=1e10+1;
    int h;
    cin>>h;
    for(int i=1;i<=h;i++)
    {
        int u;
        cin>>u;
        int j=upper_bound(x,x+m+1,u)-x-1;
        cout<<u*p[j]+q[j]<<endl;
    }
}
