// Problem: Longest Balanced Subsequence
// Description
// Given a sequence of n positive integers a = a1, a2, . . ., an. A subsequence of a is define to be the sequence generated by removing some elements of a.
// Given a positive integer D, find a subsequence S of a such that the difference between 2 adjacent elements is at most D and the number of elements of that subsequence if maximal.

// Input
// Line 1: contains 2 positive integers n and D (1 <= n <= 10000, 1 <= D <= 10000)
// Line 2: contains a1, a2,  . . ., an (1 <= ai <= 1000000)

// Output
// Write the number of elements of the subsequence found.

// Example
// Input
// 10 3
// 4 1 5 2 8 4 7 5 14 6 

// Output 
// 7

// Explanation: the subsequence found is: 4, 1, 2, 4, 7, 5, 6

#include <bits/stdc++.h>

using namespace std;

const int MAX = 10010;

int n, D;
vector<int> a(MAX);
vector<int> dp(MAX);

int main(int argc, char const *argv[]){
    cin >> n >> D;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = 1;
        for (int j = 1; j < i; j++) {
            if (abs(a[i] - a[j]) <= D) dp[i] = max(dp[i], dp[j] + 1);
        }
        res = max(res, dp[i]);
    }

    cout << res;
    return 0;
}