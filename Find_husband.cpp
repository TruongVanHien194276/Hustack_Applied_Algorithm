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

int main(int argc, char const *argv[]){
    int n, m;
    cin >> n;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    cin >> m;
    
    int closest_sum = 0;
    int res = INT_MAX;
    
    int cnt = 1 << n; 
    
    for (int v = 0; v < cnt; v++) {
        int subset_sum = 0;
        for (int i = 0; i < n; i++) {
            if (v & (1 << i)) subset_sum += a[i];
        }
        
        if (subset_sum <= m) {
            int d = m - subset_sum;
            if (d < res) {
                res = d;
                closest_sum = subset_sum;
            }
        }
    }
    
    cout << res;
    return 0;
}
