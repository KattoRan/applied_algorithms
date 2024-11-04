#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n,a[maxn];
int l[maxn],k,b[maxn];
void init()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
    k=0;
}
void tinh()
{
    for(int i=1; i<=n; i++)
    {
        int j=lower_bound(b+1,b+k+1,a[i])-b;
        {
            if(j==k+1)
                k++;
            l[j]=i;
        }
        b[j]=a[i];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
    freopen("LIS.inp","r",stdin);
    freopen("LIS.out","w",stdout);
    init();
    tinh();
    cout<<k<<endl;
    for(int i=1; i<=k; i++)
        cout<<l[i]<<" ";
}
/*
10
1 5 7 8 6 8 9 10 2 6
6
0 2 4 5 3 5 6 7 1 3*/
