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
int a[N],vt[N];
ii b[N];
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
void quicksort(int l,int r)
{
    int i=l,j=r;
    int x=a[(i+j)/2];
    while(i<=j)
    {
        while(a[i]<=x&&i!=(l+r)/2) i++;
        while(a[j]>=x&&j!=(l+r)/2) j--;
        if(i<=j) {swap(a[i],a[j]);swap(vt[i],vt[j]);
        if(vt[i]!=vt[j])cout<<vt[j]<<" "<<vt[i]<<'\n';
        i++;
        j--;}
    }
    if(j>l) quicksort(l,j);
    if(i<r) quicksort(i,r);
}

catlan()
{
    #define name "queue"
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    read(n);
    fu(i,1,n) read(a[i]),vt[i]=i;
    quicksort(1,n);
}


