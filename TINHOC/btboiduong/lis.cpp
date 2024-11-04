#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+17;
int n,a[maxn],b[maxn],l[maxn];
void kt()
{
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>a[i];
}
void timkq()
{
    int k=0;
    for(int i=1; i<=n; i++)
        {
            int j=lower_bound(b+1,b+k+1,a[i])-b;
            b[j]=a[i];
            if(j==k+1)
                k++;
            l[i]=j;
        }
    cout<<k<<"\n";
}
int main()
{
    kt();
    timkq();
    return 0;
}


