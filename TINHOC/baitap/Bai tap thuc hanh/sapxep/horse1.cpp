#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int a[maxn],b[maxn],n,m,t=0,j;
void bubblesort(int a[],int b[],int n)
{
    for(int i=n;i>=2;i--)
        for(int j=1;j<=i-1;j++)
          {if(a[j]>a[j+1]) swap(a[j],a[j+1]);
           if(b[j]>b[j+1]) swap(b[j],b[j+1]);}
}
int main()
{   ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("horse.INP","r",stdin);
    freopen("horse.OUT","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) cin>>b[i];
    bubblesort(a,b,n);
    for(int i=1;i<=n;i++)
        {   j=1;
            while(j<=n) {if(a[i]>b[j]) {t++;m=j;break;}
                         j++;}
            j=m+1;
        }
    cout<<t;
    return 0;

}
