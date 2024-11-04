#include<bits/stdc++.h>
#define task "food"
using namespace std;
const int N=1e6+7;
deque <long long> q;
long long c[N],k,m,a[N],kq;
template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-')
    {
        c=getchar();
        tam=-1;
    }
    while(isdigit(c))
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(task".inp","r",stdin);
    freopen(task".out","w",stdout);
    read(m);
    read(k);
    for(int i=1; i<=m; i++)
        read(c[i]);
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
