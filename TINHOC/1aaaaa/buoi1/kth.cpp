#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define catlan main
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=1e6+7;
long long n;
int a[N],k;
template <typename T> void read(T&x)
{
    int tam=1;
    char c=getchar();
    x=0;
    while(!isdigit(c)&&c!='-')
        c=getchar();
    if(c=='-')
        tam=-1,c=getchar();
    while(isdigit(c))
    {
        x=x*10+c-48;
        c=getchar();
    }
    x*=tam;
}
catlan()
{
#define name "median"
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    read(n);
    fu(i,1,n) read(a[i]);
    sort(a+1,a+n+1);
    if(n%2==1)
    {
        cout<<1<<endl<<a[n/2+1];
    }
    else
    {
        int d=a[n/2];
        int c=a[n/2+1];
        cout<<(c-d+1)<<endl;
        for(int i=d; i<=c; i++)
            cout<<i<<" ";
    }
}



