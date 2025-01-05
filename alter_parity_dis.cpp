// Problem: alter parity dis
// Description
// Cho một dãy số nguyên A gồm n số a1, a2, …, an. Một dãy con của dãy A là dãy thu được bằng cách xoá không hoặc một số phần tử của dãy A. Hãy tìm dãy con dài nhất có các phần tử giảm ngặt và có tính “chẵn lẻ” xen kẽ nhau, nghĩa là tổng hai phần tử liên tiếp nhau bất kỳ luôn không chia hết cho 2.
// Dữ liệu vào:
// Dòng thứ nhất chứa một số nguyên T là số bộ testcase (1 <= T <= 10).
// Mỗi nhóm dòng trong T nhóm dòng tiếp theo có cấu trúc như sau:
// - Dòng thứ nhất chứa số nguyên n là số phần tử của dãy A (1 <= n <= 10^5)
// - Dòng thứ hai chứa n số nguyên ai cách nhau bởi dấu cách (|ai| <= 10^9)
// Kết quả:
// In ra T dòng, mỗi dòng chứa một số nguyên duy nhất là độ dài của dãy con dài nhất thoả mãn yêu cầu bài toán ứng với từng testcase.
// Ví dụ:
// Dữ liệu vào
// 2
// 10
// 107 -249 14 -7 -5 17 -9 -44 41 -22
// 15
// 155 19 104 -17 5 39 69 -32 7 6 -155 -27 39 -19 -15
// Kết quả
// 4
// 5
// Giải thích:
// Với testcase 1, dãy con dài nhất có độ dài là 4, chẳng hạn dãy 107 14 -9 -44. Với testcase thứ 2, dãy con dài nhất có độ dài bằng 5 có thể là 155 104 7 6 -155.
// Lưu ý: Có 80% bộ test thoả mãn 1 <= n <= 10^4.

#include <bits/stdc++.h>

using namespace std;

int SOLVE(vector<int>& a) {
    int n = a.size();
    vector<int> dp(n, 1);

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j] && (a[i] + a[j]) % 2 != 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());
}

int main(int argc, char const *argv[]){
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << SOLVE(a) << endl;
    }

    return 0;
}
