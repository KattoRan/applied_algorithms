#include<bits/stdc++.h>
#define up(i,a,b) for(int i=1;i<=b;i++)
using namespace std;
const int mm=1e4+5;
inline void read(){;}
int n,m,s,t;
bool tata;
int c[mm][mm],f[mm][mm],trc[mm];

bool tang_luong()
{
    queue<int>q;
    trc[s]=-1;
    q.push(s);
    while(q.size())
    {
        int x=q.front();
        q.pop();
        if(x==t)return 1;
        up(i,1,n)
        {
            if(trc[i]==0&&c[x][i]-f[x][i]>0)
            {
                trc[i]=x;
                q.push(i);
            }
        }
    }
    return 0;
}

int main()
{
    #define name "a"
    ios_base::sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    #endif // Yui + ONLINE_JUDGE
    cin >> n >> m >> s >> t;
    up(i,1,m)
    {
        int u,v,z;
        cin >> u >> v >> z;
        c[u][v]=z;
    }
    while(tang_luong())
    {
        int x=t;
        int mimi=10000000;
        while(trc[x]!=-1){
            mimi=min(mimi,c[trc[x]][x]-f[trc[x]][x]);
            x=trc[x];
        }
        x=t;
        while(trc[x]!=-1)
        {
            f[trc[x]][x]+=mimi;
            f[x][trc[x]]-=mimi;
            x=trc[x];
        }
        up(i,1,n)trc[i]=0;
    }
    long long res=0;
    up(i,1,n)
    {
        res+=max(0,f[s][i]);
    }
    cout<<res;
}