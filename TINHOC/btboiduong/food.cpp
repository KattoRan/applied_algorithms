#include<bits/stdc++.h>
using namespace std;
deque <long long> q;
long long c[1000000],k,m,a[1000000],kq;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("food.inp","r",stdin);
    freopen("food.out","w",stdout);
    cin>>m>>k;
    for(int i=1; i<=m; i++)
        cin>>c[i];
    for(int i=1; i<k; i++)
    {
        while(q.empty()!=1&&c[q.back()]>=c[i])
            q.pop_back();
        q.push_back(i);
        a[i]=c[q.front()];
    }
    for(int i=k; i<=m; i++)
    {
        while(q.empty()!=1&&c[q.back()]>=c[i])
            q.pop_back();
        q.push_back(i);
        if(q.front()==i-k)
            q.pop_front();
        a[i]=c[q.front()];
    }
    for(int i=1;i<=m;i++) kq=kq+a[i];
    cout<<kq*2;
    return 0;
}
