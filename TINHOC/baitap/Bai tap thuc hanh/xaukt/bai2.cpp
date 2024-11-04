#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;
long n,k;
char s[MAXN];
int main()
{
    cin>>n>>k;
    cin>>s;
    long vitri=0,k1=k,dem=0;
    while(dem<n-k)
    {
        char max1=s[vitri];
        for(int i=vitri+1;i<=k1;i++)
           if(max1<s[i]){vitri=i;max1=s[i];}
        dem++;k1++;
        cout<<max1;
        vitri++;
    }
    return 0;
}
