// Problem: Chapter 4 - Max Even SubSequence
// Description
// Given a sequence of n integers a=a1, . . ., an. A subsequence of a consists of contiguous elements of a (for example, ai, ai+1, . . . ,aj).
// The weight of a subsequence is defined to be the sum of its elements. A subsequence is called even-subsequnce if its weight is even. Find the even-subsequence of a having largest weight.
// Input
// Line 1: contains a positive integer n (1 <= n <= 10^6)
// Line 2: contains a1, . . ., an (-10^6 <= ai <= 10^6)
// Output
// The weight of the largest even-subsequence found, or write NOT_FOUND if no solution found.
// Example
// Input
// 4
// 1  2  -3  4
// Output
// 4

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    int n;
    cin >> n;
    long long a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    long long dp0_before, dp0_cur, dp1_before, dp1_cur, res;

    if (a[1] % 2 == 0) {
        dp0_before = a[1];
        dp1_before = LONG_LONG_MIN;
    } else {
        dp1_before = a[1];
        dp0_before = LONG_LONG_MIN;
    }
    res = dp0_before;

    for (int i = 2; i <= n; i++) {
        if (a[i] % 2 == 0) {
            if (dp0_before == LONG_LONG_MIN) {
                dp0_cur = a[i];
                dp1_cur = dp1_before + a[i];
            } else if (dp1_before == LONG_LONG_MIN) {
                dp1_cur = LONG_LONG_MIN;
                dp0_cur = max(a[i], dp0_before + a[i]);
            } else {
                dp0_cur = max(a[i], dp0_before + a[i]);
                dp1_cur = dp1_before + a[i];
            }

            dp0_before = dp0_cur;
            dp1_before = dp1_cur;
            res = max(res, dp0_cur);
        } else {
            if (dp0_before == LONG_LONG_MIN) {
                dp1_cur = a[i];
                dp0_cur = dp1_before + a[i];
            } else if (dp1_before == LONG_LONG_MIN) {
                dp0_cur = LONG_LONG_MIN;
                dp1_cur = dp0_before + a[i];
            } else {
                dp0_cur = dp1_before + a[i];
                dp1_cur = max(a[i], dp0_before + a[i]);
            }

            dp0_before = dp0_cur;
            dp1_before = dp1_cur;
            res = max(res, dp0_cur);
        }
    }

    if (res == LONG_LONG_MIN) cout << "NOT_FOUND";
    else cout << res;

    return 0;
}