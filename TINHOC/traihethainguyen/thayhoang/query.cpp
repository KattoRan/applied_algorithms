#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+7;
int n,m;
int salary[maxn];
int res;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("query.inp","r",stdin);
    freopen("query.out","w",stdout);
    cin>>n>>m;
    fill(salary+1,salary+n+1,0LL);
    while(m-->0)
    {
        char s;
        int i,j;
        cin>>s>>i>>j;
        if(s=='S') salary[i]=j;
        if(s=='Q')
        {
            for(int k=i;k<=j;k++)
                res=max(res,salary[k]);
            cout<<res<<'\n';
            res=0;
        }
    }
}

