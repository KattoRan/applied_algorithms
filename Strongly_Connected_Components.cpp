#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+7;

int num[N], low[N];
int n, m;
int current = 0;
int res = 0;
vector<int> a[N];
stack<int> st;

void DFS(int curr, int p) {
    num[curr] = low[curr] = ++current;
    st.push(curr);
    for(auto next: a[curr]) {
        if(!num[next]) {
            DFS(next, curr);
            low[curr] = min(low[curr], low[next]);
        }
        else low[curr] = min(low[curr], num[next]);
    }
    if(low[curr] == num[curr]) {
        res++;
        while(st.size() && st.top() != curr) {
            int node = st.top();
            st.pop();
            num[node] = low[node] = N;
        }

        st.pop(); // pop node hien tai ra khoi stack
        num[curr] = low[curr] = N;
    }
}


int main() {
    #define name ""
    ios_base :: sync_with_stdio(NULL);
    cin.tie(nullptr);
    cout.tie(nullptr);
    #ifndef ONLINE_JUDGE
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    #endif // ONLINE_JUDGE

    cin >> n >> m;
    for(int i = 1; i <= m; ++i) {
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
    }   

    for(int i = 1; i <= n; ++i) {
        if(!num[i]) {
            DFS(i, i);
        }
    }
    /*for (int i = 1; i <= n; i++)
        if(low[i] == num[i]) res++;*/

    cout << res << '\n';

    // cerr<<"Running Time: "<<clock()/double(1000) <<"s\n";
    return 0;
}