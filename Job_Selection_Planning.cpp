#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N = 1e6+7;
int n;
pair<int,int> a[N];

int cmp(pair<int,int> a, pair<int,int> b)
{
    return (a.se < b.se);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    priority_queue<pair<int,int>,vector<pair<int,int> >, greater<pair<int,int> > > q;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].se >> a[i].fi;
    sort(a+1,a+n+1,cmp);
    long long kq = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i].se > q.size()) q.push(a[i]);
        else {
            if (q.size())
            if (q.top().fi < a[i].fi)
            {
                //cout << a[i].fi << " " << a[i].se << '\n';
                q.pop();
                q.push(a[i]);
            }
        }
    }
    while (!q.empty())
    {
        kq+=q.top().fi;
        q.pop();
    }
    cout << kq;
    return 0;
}
