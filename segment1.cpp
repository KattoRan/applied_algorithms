#include<bits/stdc++.h>
#define fort(i,a,b) for(int i=a;i<=b;i++)
typedef long long ll;

using namespace std;
const int maxn=1e6+7;

int leaf[4*maxn], maxx[4*maxn];
int a[maxn];
int n;
int qi,qj;
void build(int x,int low,int high)
{
    if(low==high)
    {
        maxx[x] = a[low];
        leaf[low]= x;
    }
    else
    {
        int middle = (low+high)/2;
        build(2*x,low,middle);
        build(2*x+1,middle+1,high);
        sum[x] = sum[2*x]+sum[2*x+1];
    }
}
void update(int k,int w)
{
    int x = leaf[k];
    sum[x] = w;
    for(x/=2;x>0;x/=2)
    sum[x] = sum[2*x]+sum[2*x+1];
}
int request(int x)
{
    if(qi>h[x]&&qj<l[x])return 0;
    if(qi<=l[x]&&h[x]<=qj) return sum[x];
    return request(2*x)+request(2*x+1);
}
int query(int i,int j)
{
    qi=i;qj=j;
    return request(1);
}
main()
{
    cin>>n;
    build(1,1,n);
    update(3,5);
}

