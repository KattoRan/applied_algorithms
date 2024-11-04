#include <bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
const int N = 1e6 + 7;
int n, q, a[N];

namespace segement
{
	struct Node
	{
		int lazy;
		int val;
	} st[4*N];

	void build (int id, int l, int r)
	{
		if (l == r)
		{
			st[id].val = a[l];
			return;
		}
		int mid = (l+r)/2;
		build(id*2, l, mid);
		build(id*2+1, mid+1, r);
		st[id].val = max(st[id*2].val ,st[id*2+1].val);
	}
	void down(int id)
	{
		int t = st[id].lazy;
		st[id*2].val += t;
		st[id*2].lazy += t;
		st[id*2+1].val += t;
		st[id*2+1].lazy += t;
		st[id].lazy = 0;
	}
	void update(int id, int l, int r, int u, int v, int w)
	{
		if (v < l || u > r) return;
		if (u <= l && r <= v)
		{
			st[id].val += w;
			st[id].lazy += w;
			return;
		}
		int mid = (l+r)/2;
		down(id);
		update(id*2,l,mid,u,v,w);
		update(id*2+1,mid+1,r,u,v,w);
		st[id].val = max(st[id*2].val , st[id*2+1].val);
	}
	int Get(int id, int l, int r, int u, int v)
	{
		if (v < l || u > r) return 0;
		if (u <= l && r <= v) return st[id].val;
		int mid = (l+r)/2;
		down(id);
		return max(Get(id*2,l,mid,u,v),Get(id*2+1,mid+1,r,u,v));
	}
}
int main()
{
   /* ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen(".inp","r",stdin);
    freopen(".out","w",stdout);*/
    cin>>n;
    fu(i,1,n) cin>>a[i];
    segement :: build(1,1,n);
    cin>>q;
    fu(i,1,q)
    {
        string s;
        cin >> s;
        if (s == "get-max")
        {
            int u,v;
            cin>>u>>v;
            cout<<segement :: Get(1,1,n,u,v)<<'\n';
        }
        else
        {
            int u,v;
            cin>>u>>v;
            segement :: update(1,1,n,u,u,v-a[u]);
            a[u] = v;
        }


    }
}
