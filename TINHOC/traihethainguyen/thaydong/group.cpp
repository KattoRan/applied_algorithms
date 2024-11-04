#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fort(i,a,b) for(int i=a;i<=b;i++)
const int maxn=55;
int n,m;
int best,a[maxn][maxn];
int ni[maxn];
ll li;
void clique(ll u,ll c)
{
    fort(i,1,n)
    fort(j,1,n)
    if(a[i][j]) ni[i]|=(1<<j);
    int cntu=0;
    fort(i,1,n)
    if(u&(1LL<<i))
    {
        cntu++;
        li=i;
    }
    int cntc=0;
    fort(i,1,n)
    if(c&(1LL<<i)) cntc++;
    if(u==0) if(cntu>=best) best=cntu;
    if(cntu+cntc<=best) return;
    clique(u&n[li],c|(1LL<<li));
    clique(u^(1LL<<li,c))

}
void split(int i,int A[] ,int B[])
{
    if(i>n)
    {
        best=0;
        clique(A,0);
        besta=best;
        best=0;
        clique(B,0);
        if(besta==best) cout<<A;
    }
    split(i+1,A|(1<<i),B);
    split(i+1,A,B|(1<<i));
}
int main()
{
    cin>>n>>m;
    fort(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        a[u][v]=a[v][u]=1;
    }


}

