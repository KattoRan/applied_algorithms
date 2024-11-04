// Cat \\
||*---*||
#include<bits/stdc++.h>
#define fu(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define fi first
#define se second
#define catlan main
#define bit(X,i) ((X>>i)&1)
#define on(X,i) (X|(1<<i))
#define off(X,i) (X^(1<<i))
#define dembit(X) __builtin_popcount(X)
using namespace std;

const int N=1e6+7;

typedef long long ll;
typedef pair<int,int> ii;

int n,k;
double p[N];
template <typename T> inline void read(T &x)
{
    x=0;
    char c=getchar();
    int tam=1;
    while(!isdigit(c)&&c!='-') c=getchar();
    if(c=='-')
    {
        tam=-1;
        c=getchar();
    }
    while(isdigit(c))
    {
        x=x*10+(c-48);
        c=getchar();
    }
    x*=tam;
}

void ent()
{

}

void solve()
{

}

void sub1()
{
    sort(p+1,p+k+1);
    double res1,res2;
    if(double(p[1]/p[4])<=double(p[2]/p[3]))
    {
        res1= double(p[1]/p[4])+double(p[2]/p[3]);
    }
    if(double(p[2]/p[4])<=double(p[1]/p[3]))
    {
        res2= double(p[2]/p[4])+double(p[1]/p[3]);
    }
    if(res1<=res2) cout<<p[1]<<" "<<p[4]<<" "<<p[2]<<" "<<p[3]<<endl;
    else cout<<p[1]<<" "<<p[3]<<" "<<p[2]<<" "<<p[4]<<endl;
}

void sub2()
{
    double res = 1e18;
    int r1,r2,r3,r4;
    for (int a = 1; a <= k; a++)
    for (int b = 1; b <= k; b++)
    if (b != a && p[b] != 0){
    for (int c = 1; c <= k; c++)
        if (c != a && c != b){
            for (int d = 1; d <= k; d++)
                if (d != a && d != c  && d != b && p[d] != 0){
                    if (p[a] * p[d] <= p[b] * p[c]){
                        double t = (p[a]*p[d] + p[b]*p[c]) * 1.0 / (p[b]*p[d]);
                        if (res > t){
                                res = t;
                                r1 = p[a]; r2 = p[b]; r3 = p[c]; r4 = p[d];}
                        }
                    }
                }
            }
    cout<<r1<<" "<<r2<<" "<<r3<<" "<<r4<<endl;
}
void sub3()
{
    double res = 1e18;
    sort(p+1,p+k+1);
    int A, B, C, D;
    for (int i = 1; i <= k; i++)
        for (int j = i+1; j <= k; j++)
    {
        double a = p[i], b = p[j];
        int g = 1, h = k;
        while (h == i || h == j) h--;
        double d = p[h];
        while (g == i || g == j || g == h) g++;
        double c = p[g];
        double res1 = double (a / b) + double (c / d);
        if (double (a / b) > double (c / d)) swap (a, c), swap (b, d);
        if(res > res1)
        {
            res = res1;
            A = a; B = b; C = c; D = d;
        }
    }
    cout<<A<<" "<<B<<" "<<C<<" "<<D<<endl;
}
catlan()
{
    #define name "minsum"
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen(name".inp","r",stdin);
    freopen(name".out","w",stdout);
    //ent();
    //solve();
    cin>>n>>k;
    while(n--)
    {
        fu(i,1,k) cin>>p[i];
        /*if(k==4) sub1();
        else if(n*k<=1e6) sub2();
             else sub3();*/
        sub3();
    }
}
