#include<bits/stdc++.h>
using namespace std;
const int N=107;
typedef struct point{double x,y;};
point p[N];
int n;
double res;
double dientich(int i,int j)
{
    double tg=0,s;
    p[j+1]=p[i];
    for(int k=i;k<=j;k++)
        tg+=(p[k+1].y+p[k].y)*(p[k+1].x-p[k].x);
    s=abs(tg)/2;
    return s;
}
int main()
{
    cin>>n;
    res=1000000;
    for(int i=1;i<=n;i++)
        cin>>p[i].x>>p[i].y;
    double s=dientich(1,n);

}
