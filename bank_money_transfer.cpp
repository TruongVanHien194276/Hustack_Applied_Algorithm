// Problem: bank money transfer
// Description
// A bank needs to transfer n bags of money from its headquarters to its branches using two specialized cash transport vehicles with equal transportation capabilities. Each money bag has a value. To minimize operational risk, the cash transport coordinator needs to divide these n money bags between the two vehicles so that the difference in the total value of money transported by these two vehicles is as small as possible.
// (Ngân hàng cần chuyển n túi tiền từ trụ sở chính đến các chi nhánh của mình bằng hai xe chuyên dụng chở tiền có khả năng vận chuyển bằng nhau. Mỗi túi tiền có một giá trị nhất định. Để giảm thiểu rủi ro hoạt động, người điều phối vận chuyển tiền cần phải chia những túi tiền này cho hai xe sao cho sự chênh lệch về tổng giá trị tiền được vận chuyển bởi hai xe này càng nhỏ càng tốt.)

// Input/Đầu vào
// Row 1: A integer representing the number of cash bags, n (1 <= n <= 20) (Một số nguyên biểu thị số lượng túi tiền, không xác định)
// Row 2: n integers separated by by spaces, each representing the value of a cash bag. These integers range from 1 to 1000 (n số nguyên được phân cách bằng dấu cách, mỗi số biểu thị giá trị của một túi tiền. Những số nguyên này nằm trong khoảng từ 1 đến 1000.)
// Output/Đầu ra
// An integer representing the smallest possible difference in the total values of money transported by the two vehicles. (Một số nguyên biểu thị cho sự chênh lệch nhỏ nhất có thể trong tổng giá trị tiền được vận chuyển bởi hai xe.)
// Example/Ví dụ
// Input   (stdin)
// 5
// 208   750 114 184 538
// Output (stdout)
// 66

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int n;
vector<int> a;
int res = INF;

void SOLVE(int i, int s1, int s2) {
    if (i == n) {
        res = min(res, abs(s1 - s2));
        return;
    }

    SOLVE(i + 1, s1 + a[i], s2);
    SOLVE(i + 1, s1, s2 + a[i]);
}

int main(int argc, char const *argv[]){
    cin >> n;
    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    SOLVE(0, 0, 0);
    cout << res;
    
    return 0;
}