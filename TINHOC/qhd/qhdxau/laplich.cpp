#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
struct tp{int p,d,vt;};
tp a[maxn],b[maxn];
int n,dem[maxn];
void init()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i].p;
    for(int i=1; i<=n; i++)
        cin>>a[i].d;
    for(int i=1; i<=n; i++)
        a[i].vt=i;
}
bool kt(int n,tp cv[maxn])
{
    for(int i=1; i<=n-1; i++)
        for(int j=i+1; i<=n; i++)
            if (cv[i].d > cv[j].d)
                swap(cv[i], cv[j]);
    int t=0;
    for(int i=1; i<=n; i++)
    {
        if (t + cv[i].p > cv[i].d)
            return false;
        t= t + cv[i].p;
    }
    return true;
}
void xuli()
{
    for(int i=1; i<=n-1; i++)
        for(int j=i+1; i<=n; i++)
            if (a[i].d > a[j].d)
                swap(a[i], a[j]);
    int m=0;
    for(int i=1; i<=n; i++)
    {
        b[m+1]=a[i];
        if (kt(m+1,b))
        {
            dem[i]=1;
        }
    }
    for(int i=1; i<=n; i++)
        if(dem[i]==0)
        {
            m=m+1;
            b[m]=a[i];
        }
}
int main()
{
    init();
    xuli();
    for(int i=1;i<=n;i++) cout<<b[i].vt<<" ";
    return 0;
}
