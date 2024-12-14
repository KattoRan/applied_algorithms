#include <bits/stdc++.h>
using namespace std;
const int N = 1e6+7;

long long a[N],n,k1,k2,dp[N];
long long res = 0;
long long b[N];

int main()
{
    #define name "a"
    ios_base:: sync_with_stdio(0),cin.tie(0),cout.tie(0);
    freopen(name".inp","r",stdin);
//    freopen(name".out","w",stdout);

    cin >> n >> k1 >> k2;
    for (int i = 1; i <= n; i++) cin >> a[i];

    /*priority_queue<pair<int,int> > pq;
    for (int i = 1; i <= n; i++)
    {
        if (i-k1>0) pq.push({dp[i-k1],i-k1});
        else dp[i] = a[i];
        while(pq.size() && pq.top().second < i - k2) pq.pop();

        if(pq.size() && (i - k2 <= pq.top().second && i - k1 >= pq.top().second)) dp[i] = pq.top().first + a[i]; 
    }
    for (int i = 1; i <= n; i++) res = max(res,dp[i]);
    cout << res << endl;
    return 0;*/
    deque<long long> dq;
    for (int i = 1; i <= n; i++)
    {
        while(dq.size() && dp[dq.back()] <= dp[i-k1]) dq.pop_back();
        if (i-k1>0) dq.push_back(i-k1);
        while (dq.size() && dq.front() < i-k2) dq.pop_front();
        if(dq.size() && (i - k2 <= dq.front() && i - k1 >= dq.front())) dp[i] = dp[dq.front()] + a[i];
        else dp[i] = a[i];
    }
    for (int i = 1; i <= n; i++) res = max(res,dp[i]);
    cout << res << endl;
    return 0;
}


