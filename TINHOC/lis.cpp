#include<bits/stdc++.h>
#define fort(a,b,c) for(int a=b;a<=c;a++)

using namespace std;
const int maxn=1e6+7;
struct data{int a;int id;} c[maxn],t[maxn];
int n,f[maxn],a[maxn],b[maxn],trc[maxn],k=0;
int l[maxn];

void up(int x,int w,int i)
{
    for(;x<=n;x+=(x&-x)) t[x].a=max(t[x].a,w),t[x].id=i;
}
data Get(int x)
{
    data r;
    r.a=0;r.id=0;
    for(;x>=1;x-=(x&-x)) if(r.a<t[x].a) {r.a=t[x].a;r.id=t[x].id;}
    return r;
}

bool cmp(data x, data y)
{
    return x.a<y.a;
}

void calc()
{
    sort(c+1,c+n+1,cmp);
    int k=1;
    b[c[1].id]=k;
    fort(i,2,n)
    {
        if(c[i].a>c[i-1].a) k++;
        b[c[i].id]=k;
    }
    fort(i,1,n) a[i]=b[i];
}
 void vet(int i)
 {
     if(i)
     {
         k++;
         l[k]=i;
         vet(trc[i]);
     }
 }
main()
{
    freopen("lis.inp","r",stdin);
    freopen("lis.out","w",stdout);
    cin>>n;
    fort(i,1,n) cin>>a[i];
    fort(i,1,n) c[i].a=a[i],c[i].id=i;
    calc();
    int res=0,vt;
    fort(i,1,n)
    {
        data h;
        h=Get(a[i]-1);
        f[i]=h.a+1;
        trc[i]=h.id;
        up(a[i],f[i],i);
        if(res<f[i]) res=f[i],vt=i;
    }
    cout<<res<<"\n";
    vet(vt);
    for(int i=k;i>=1;i--) cout<<l[i]<<" ";
}
