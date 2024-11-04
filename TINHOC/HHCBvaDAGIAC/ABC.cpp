#include<bits/stdc++.h>
using namespace std;
struct point {int x,y;};
point a,b,c;
void PTDT(point p1,point p2,int &x, int &y,int &z)
{
    x=p2.y-p1.y;
    y=p1.x-p2.x;
    z=-(x*(p1.x)+y*(p1.y));
}
bool DTDT(point p,point p1,point p2)
{
    int x,y,z;
    PTDT(p1,p2,x,y,z);
    return (x*p.x+y*p.y+z==0);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("ABC.inp","r",stdin);
    //freopen("ABC.out","w",stdout);
    cin>>a.x>>a.y>>b.x>>b.y>>c.x>>c.y;
    if(DTDT(a,b,c)) cout<<"NO";
    else cout<<"YES";
}
