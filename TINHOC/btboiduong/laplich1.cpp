#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
struct tp
{
    int p,d,vt;
};
tp a[maxn];
int n,f[maxn],tg,d,t,cs;
bool cmp(tp x,tp y)
{
    return  x.d<y.d;
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i].p;
    for(int i=1; i<=n; i++)
        cin>>a[i].d;
    for(int i=1; i<=n; i++)
        a[i].vt=i;
    sort(a+1,a+n+1,cmp);
    tg=0;
    for(int i=1; i<=n; i++)
    {
        d++;
        f[d]=i;
        if(tg+a[i].p<=a[i].d)
        {
            tg+=a[i].p;
        }
        else
        {
            int mint,t;
            mint=tg;
            for(int j=1; j<=d; j++)
            {
                t=tg-a[f[j]].p+a[j].p;
                if(t<mint&&t<=a[i].d)
                {
                    cs=j,mint=t;
                }
            }
            if(cs!=0)
            {
                for(int k=cs; k<=d; k++)
                    f[k]=f[k+1];
            }
            tg=mint;
        }
    }
    cout<<d<<endl;
    for(int i=1; i<=d; i++)
        cout<<a[f[i]].vt<<" ";
}
