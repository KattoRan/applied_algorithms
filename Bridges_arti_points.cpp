#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+7;

int num[N], low[N];
int n, m;
int current = 0;
int articulation, bridge;
vector<int> a[N];

void DFS(int curr, int p) {
    num[curr] = low[curr] = ++current;
    int child = 0;
    bool isArticulation = false;
    for(auto next: a[curr]) {
        if(next == p) continue;
        if(!num[next]) {
            DFS(next, curr);
            child++;
            low[curr] = min(low[curr], low[next]);
            if(low[next] >= num[curr] && curr != p) {
                isArticulation = true;
            }
        }
        else low[curr] = min(low[curr], num[next]);
        if(low[next] > num[curr]) {
            bridge++;
        }
    }
    if(curr == p && child > 1) {
        isArticulation = true;
    }
    articulation += isArticulation;
}


int main() {
    #define name ""
    ios_base :: sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    // freopen(name".inp","r",stdin);
    // freopen(name".out","w",stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }   

    for(int i = 1; i <= n; ++i) {
        if(!num[i]) {
            DFS(i, i);
        }
    }

    cout << articulation <<" "<<bridge << '\n';

    // cerr<<"Running Time: "<<clock()/double(1000) <<"s\n";
    return 0;
}