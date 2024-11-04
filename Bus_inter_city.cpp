#include<bits/stdc++.h>
using namespace std;
const int N = 1e4+7;
const int oo=1e9+1;
typedef pair<int,int> ii;
vector <ii> a[N];
int n,m;
int dx[N],d[N],c[N];
int dist[N];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> c[i] >> d[i];

    for (int i = 1; i <= m; i++)
    {
        int u,v;
        cin >> u >> v;
        a[u].push_back({c[u],v});
        a[v].push_back({c[v],u});
    }
    for (int i = 1; i <= n; i++) dist[i] = oo;

    priority_queue<ii,vector<ii>,greater<ii> >pq;
    pq.push({0,1});
    dist[1] = 0;
    while(pq.size())
    {
        int u = pq.top().second;
        int du = pq.top().first;
        pq.pop();
        //cout << endl;
        if(du!=dist[u]) continue;
        //BFS
        queue<int> q;
        int step = 0;
        q.push(u);
        dx[u] = 1;
        while (q.size() && step < d[u])
        {
            int uu = q.front();
            q.pop();
            for (int i = 0; i < a[uu].size(); i++)
            {
                int v = a[uu][i].second;
                if(!dx[v])
                {
                    dx[v] = 1;
                    if (step < d[u] && step > 0)
                    {
                        if(dist[v] > dist[uu])
                        {
                            dist[v] = dist[uu];
                            pq.push({dist[v],v});
                        }
                    }
                    else
                        if(dist[v] > dist[uu] + c[uu])
                        {
                            dist[v] = dist[uu] + c[uu];
                            pq.push({dist[v],v});
                        }
                    q.push(v);
                    //cout << uu << " " << v << " " << step << " " << dist[v] << endl;
                }
            }
            ++step;
        }
    }

    cout << dist[n];
}
