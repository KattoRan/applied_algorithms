#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+7;
struct tp
{
    int p,d,vt;
};
tp a[maxn];
bool b[maxn];
int n,c,t[maxn];
priority_queue <pair<int,int> > q;
bool cmp(tp x,tp y)
{
    return  x.d<y.d;
}
bool opt(int x,int y)
{
    return t[x]<t[y];
}
void init()
{
    cin>>n;
    for(int i=0; i<n; i++)
        cin>>a[i].p;
    for(int i=0; i<n; i++)
        cin>>a[i].d;
    for(int i=0; i<n; i++)
        a[i].vt=i;
    sort(a,a+n,cmp);
    for(int i=0; i<n; i++)
        t[a[i].vt]=a[i].d;
}
void xuli()
{
    c=0;
    for(int i=0; i<n; i++)
    {
        q.push(make_pair(a[i].p,a[i].vt));
        c+=a[i].p;
        while (c>a[i].d)
        {
            pair<int,int> pp=q.top();
            q.pop();
            c-=pp.first;
        }
    }
    vector<int> v;
    while (!q.empty())
    {
        pair<int,int> pp = q.top();
        q.pop();
        v.push_back(pp.second);
    };
    sort(v.begin(),v.end(),opt);
    int ok = v.size();
    for(int i=0; i<n; i++) b[i]=true;
    cout<<n - ok<<endl;
    for (int i=0;i<ok; i++)
    {
        cout<<v[i]+1<<" ";
        b[v[i]] = false;
    }
    for (int i=0; i<n; i++)
        if (b[i])
         cout<<i+1<<" ";
}

int main()
{
    init();
    xuli();
    return 0;
}
