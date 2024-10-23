// Problem: Find husband
// Description
// Để tìm kiếm chồng là một anh chàng khoa học máy tính, công chúa của một đất nước ra một đề toán như sau: Cho n số nguyên, hãy chọn một tập con của tập n số nguyên này sao cho tổng của các số nguyên được chọn không vượt qua M cho trước và hiệu giữa M và tổng của những số nguyên được chọn là nhỏ nhất.
// Đầu vào
// · Dòng 1: Số nguyên n (1 <= n <= 20)
// · Dòng 2: n số nguyên cách nhau bởi dấu cách, giá trị của các số nguyên này nằm từ 1 tới 1000
// · Dòng 3: Số nguyên M (1 <= M <= 100000)
// Đầu ra
// · Một số tự nhiên là hiệu của M và tổng của các số nguyên được chọn nhỏ nhất.
// Ví dụ
// Input   (stdin)
// 5
// 208   750 114 184 538
// 897
// Output   (stdout)
// 33

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n;              
vector<int> a; 
int M;               
int res = INF; 

void TRY(int i, int sum) {
    if (i == n) {
        if (sum <= M) {
            int diff = M - sum;
            res = min(res, diff);
        }
        return;
    }

    TRY(i + 1, sum + a[i]);
    TRY(i + 1, sum);
}

int main(int argc, char const *argv[]){
    cin >> n;
    a.resize(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    cin >> M;

    TRY(0, 0);
    cout << res;

    return 0;
}
