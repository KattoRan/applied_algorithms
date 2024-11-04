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

vector<int> p; // Mảng lưu thông tin tiền tố
string s, t; // Chuỗi lớn s và chuỗi con t
int n, m; // Độ dài của chuỗi t và s
int k = 0; // Chỉ số cho chuỗi tiền tố
int cnt = 0; // Đếm số lần khớp

void KMP()
{
    m = s.length();
    s = "+"+s;
    p.resize(m + 1);
    p[0] = -1; // Khởi tạo p[0]

    for (int i = 1; i <= m; i++)
    {
        while (k >= 0 && s[i] != s[k + 1])
        {
            k = p[k];
        }
        if (s[i] == s[k + 1])
        {
            k++;
        }
        p[i] = k; // p[i] là số j lớn nhất sao cho s[j] == s[i]
    }
}

void sokhop()
{
    n = t.length();
    t = "+"+t;
    for (int i = 1; i <= n; i++)
    {
        while (k > 0 && s[k + 1] != t[i])
        {
            k = p[k];
        }
        if (s[k + 1] == t[i])
        {
            k++;
        }
        if (k == m)   // Khớp hoàn toàn
        {
            int a = i - m + 1; // a là vị trí khớp
            //cout << "Tim thay khop tai vi tri: " << a << endl;
            k = p[k]; // Tiếp tục tìm kiếm
            cnt++;
        }
    }
}

int main()
{
#define name ""
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen(name".inp","r",stdin);
    //freopen(name".out","w",stdout);
    getline(cin, s); // Nhập chuỗi lớn
    getline(cin, t); // Nhập chuỗi con

    KMP(); // Xây dựng mảng tiền tố
    sokhop(); // Tìm kiếm chuỗi con

    cout << cnt << endl;
    return 0;
}
