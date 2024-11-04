#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int n,a[N],k;
int b[N],l[N];
vector<int> kq;
bool cmp(int a,int b)
{
    return a>b;
}
main()
{
    ios_base::sync_with_stdio(0);
     cin.tie(0);
     cout.tie(0);
    //freopen("lds.inp","r",stdin);
    //freopen("lds.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    k=0;
    for(int i=1;i<=n;i++)
    {
        int j=lower_bound(b+1,b+k+1,a[i],cmp)-b;
        if(j==k+1) k++;
        l[j]=i;
        b[j]=a[i];
    }
    cout<<k<<'\n';
    int j=k,i=n;
    while(j>0)
    {
        if(l[j]==i) {kq.push_back(i);j--;}
        i--;
    }
    for(int i=kq.size()-1;i>=0;i--)
    cout<<kq[i]<<" ";

}
