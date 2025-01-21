#include <bits/stdc++.h>
using namespace std;

const int oo = 1e6 + 7;

int n, m, k;
int res = oo;
vector<int> a[31];      // Lớp học có thể phân cho từng giảng viên
int load[11];           // Số lớp hiện tại mà mỗi giảng viên nhận
int b[31][31];          // Ràng buộc giữa các lớp học
int x[31];              // Giảng viên được phân cho lớp học
int minLoad[11];        // Số lớp tối thiểu mà giảng viên cần nhận

// Kiểm tra lớp u có thể phân cho giảng viên v không
bool check(int u, int v)
{
    for (int i = 1; i < u; i++)
    {
        if (x[i] == v && b[u][i]) // Ràng buộc giữa lớp u và lớp i
            return false;
    }
    return true;
}

// Kiểm tra điều kiện số lớp tối thiểu
bool isValid()
{
    for (int i = 1; i <= m; i++)
        if (load[i] < minLoad[i]) return false;
    return true;
}

// Cập nhật kết quả nếu tìm thấy lời giải hợp lệ
void solution()
{
    if (!isValid()) return; // Kiểm tra điều kiện số lớp tối thiểu
    int res1 = load[1];
    for (int i = 2; i <= m; i++)
        res1 = max(res1, load[i]);
    res = min(res, res1);
}

void Try(int i)
{
    for (auto j : a[i]) // Duyệt qua các giảng viên có thể nhận lớp i
        if (check(i, j))
        {
            x[i] = j;
            load[j]++;
            if (i == n) solution();
            else
            {
                if (load[j] < res) Try(i + 1); // Cắt nhánh
            }
            load[j]--;
        }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    // Nhập số giảng viên và số lớp học
    cin >> m >> n;

    // Nhập danh sách lớp học có thể được giao cho từng giảng viên
    for (int i = 1; i <= m; i++)
    {
        int kk; cin >> kk;
        for (int j = 1; j <= kk; j++)
        {
            int u; cin >> u;
            a[u].push_back(i);
        }
    }

    // Nhập số lớp tối thiểu mà mỗi giảng viên cần nhận
    for (int i = 1; i <= m; i++)
        cin >> minLoad[i];

    // Nhập ràng buộc giữa các lớp học
    cin >> k;
    while (k--)
    {
        int u, v;
        cin >> u >> v;
        b[u][v] = 1;
        b[v][u] = 1;
    }

    // Gọi thử tất cả các cách phân lớp học
    Try(1);

    // In kết quả
    if (res == oo) cout << -1; // Không tìm được lời giải
    else cout << res;

    return 0;
}
