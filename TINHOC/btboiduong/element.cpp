#include<bits/stdc++.h>
using namespace std;
const int maxn=10e5;
int a[maxn],n;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    int t=*max_element(a+1,a+n+1);
    int h=*min_element(a+1,a+n+1);
    cout<<"max: "<<t<<endl;
    cout<<"min: "<<h<<endl;
    return 0;
}
