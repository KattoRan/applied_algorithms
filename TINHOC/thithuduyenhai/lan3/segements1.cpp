#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int n;
int t;
long long a[maxn];
int tknp(int dau,int cuoi,int x)
{
    int giua;
    while (dau<=cuoi)
    {
        giua=(dau+cuoi)/2;
        if (a[giua]==x)
            return giua;
        else
        {
            if (a[giua]>x)
                cuoi=giua-1;
            else
                dau=giua+1;
        }
    }
    return 0;
}

bool check(int x,int sl)
{
    int id,vt;
    id=0;
    for (int i=1; i<= sl; i++)
    {
        vt=tknp(id,n,a[id]+x);
        if (vt==0)
            return false;
        id=vt;
    }
    return true;
}
void xuli()
{
    int i,j;
    i=a[n];
    if (a[n]%i==0)
    {
        if (check(a[n]/i, i))
        {
            cout<<i<<" ";
            exit(0);
        }
    }
    i=a[n]/2;
    if (a[n]%i==0)
    {
        if (check(a[n]/i, i))
        {
            cout<<i<<" ";
            exit(0);
        }
    }

    int m=sqrt(a[n]);
    for (i=m; i>=2; i--)
    {
        if (a[n]%i==0)
        {
            if (check(a[n]/i, i))
            {
                cout<<i;
                exit(0);
            }
        }
    }
    cout<<1<<" ";
}
int main()
{
    cin>>n;
    a[0]=0;
    for(int i=1; i<=n; i++)
        cin>>a[i],a[i]=a[i-1]+a[i];
    xuli();
    return 0;
}
