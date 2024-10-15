// Problem: LAB.02.01 - Count solutions to an integer linear equation
// Description
// Given a positive integer n and n positive integers a1, a2, ..., an. 
// Compute the number of positive integer solutions to the equation:
//                           a1X1 + a2X2 + . . . + anXn = M

// Input
// Dòng 1: n và M
// Dòng 2: a1, a2, ..., an
// Output
//    Số nghiệm nguyên dương
// Ví dụ
// Input
// 3 5
// 1 1 1
// Output
// 6

#include <bits/stdc++.h>

using namespace std;

int Count(int n, int M, const vector<int> a) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        s += a[i];
    }

    if (M < s) return 0;

    int target = M - s;
    vector<int> dp(target + 1, 0);
    dp[0] = 1; 
    for (int i = 0; i < n; i++) {
        for (int j = a[i]; j <= target; j++) {
            dp[j] += dp[j - a[i]];
        }
    }

    return dp[target];
}

int main(int argc, char const *argv[]){
    int n, M;
    cin >> n >> M;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << Count(n, M, a);

    return 0;
}
