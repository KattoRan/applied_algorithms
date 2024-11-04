#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N=1e5+7;
pair<int,int> c[N];
int b[N];
int a[N];
int aa[N][21];
ll f[N],t[N];
int n,m;

void up(int x,ll w)
{
    for(;x<=n;x+=x&-x)
        t[x]=max(t[x],w);
}
ll get(int x)
{
    ll res=0;
    for(;x>0;x&=x-1)
        res=max(res,t[x]);
    return res;
}

void sub1()
{
    fu(i,1,n) cin>>a[i];
    fu(i,1,n) c[i].fi=a[i],c[i].se=i;
    int k=1;
    sort(c+1,c+n+1);
    b[c[1].se]=k;
    fu(i,2,n)
    {
        if(c[i].fi>c[i-1].fi) k++;
        b[c[i].se]=k;
    }
    fu(i,1,n)
    {
        f[i]=get(b[i]-1)+1;
        up(b[i],f[i]);
    }
    cout<<*max_element(f+1,f+n+1);
}
void sub2()
{
    fu(i,1,n)
    {
        fu(j,1,m)  cin>>aa[i][j];
        sort(aa[i]+1,aa[i]+m+1);
    }
    fu(i,1,n)
    {
        fu(j,1,i-1)
        {
            bool dd=1;
            fu(k,1,m)
            {
                if(aa[i][k]<=aa[j][k]) {dd=0;break;}
            }
            if(dd) f[i]=max(f[i],f[j]);
        }
        f[i]++;
    }
    cout<<*max_element(f+1,f+n+1);
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("vector.inp","r",stdin);
    freopen("vector.out","w",stdout);
    cin>>n>>m;

    if(m==1) sub1();
    else sub2();
}
