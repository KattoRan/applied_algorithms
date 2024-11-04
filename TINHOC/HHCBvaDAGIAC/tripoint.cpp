#include<bits/stdc++.h>
#define ll long long
#define dd double
#define foru(i,a,b) for(int i=a;i<=b;i++)
#define maxn 10000
using namespace std;
typedef struct point
{
    int x,y;
};
point a[maxn];
dd dx,dy;
int res,n;

void vtcp(point p1, point p2,dd &dx,dd &dy)
{
    dx=p2.x-p1.x;
    dy=p2.y-p1.y;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("tripoint.inp","r",stdin);
    freopen("tripoint.out","w",stdout);
    cin>>n;
    foru(i,1,n) cin>>a[i].x>>a[i].y;
    res=0;
    foru(i,1,n-1)
    {
        vector <dd> b;
        int d1=0;
        foru(j,i+1,n)
        {
            vtcp(a[i],a[j],dx,dy);
            if (dx==0)
                d1++;
            else
                b.push_back((dd)dy/dx);

        }
        res+=(int)(d1*(d1-1)/2);
        int d2=1;
        sort(b.begin(), b.end());
        b.push_back(INT_MAX);
        int t=b.size()-2;
        foru(i,0,t)
        {
            if (b[i]==b[i+1])
                d2++;
            else
                res+=(int)(d2*(d2-1)/2),d2=1;
        }
    }

    cout<<res;
    return 0;
}

