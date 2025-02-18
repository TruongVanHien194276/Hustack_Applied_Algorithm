// Problem: Longest Consecutive Increasing Subsequence
// Description
// Cho dãy a = a1, a2, ..., an. Một dãy con của dãy a được định nghĩa là 1 dãy gồm các phần tử liên tiếp đứng cạnh nhau của a (ai, ai+1,..., aj). Hãy tìm dãy con tăng dần có số phần tử lớn nhất.
// Input
// Dòng 1: số nguyên dương n (2 <= n <= 100000)
// Dòng 2: dãy a1, a2, . . ., an (1 <= ai <= 1000000)

// Output
// Ghi ra số phần tử của dãy con tìm được.

// Example
// Input 
// 10
// 10 2 3 4 5 9 8 5 8 10 

// Output 
// 5

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int res = 1, cur = 1;

    for (int i = 1; i < n; i++) {
        if (a[i] > a[i - 1]) {
            cur++;
            res = max(res, cur);
        } else cur = 1;
    }

    cout << res;
    return 0;
}
