// roblem: Max Subsequence No 2 adjacent elements selected
// Description
// Given a sequence of positive integers a1, . . ., an. Select the subset of elements such that the sum is maximal and no 2 adjacent elements are selected.
// Input
// Line 1: contains a positive integer n (1 <= n <= 100000)
// Line 2: contains a1, . . ., an (1 <= ai <= 1000)
// Output
// Write the sum of elements of the subseq found
// Example
// Input
// 5
// 2 5 4 6 7
// Output
// 13

// Explanation the subset found is: {2, 4, 7}

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;
vector<long long> dp;

long long SOLVE(int i) {
    if (i < 0) return 0;
    if (dp[i] != -1) return dp[i];
    return dp[i] = max(SOLVE(i - 1), SOLVE(i - 2) + a[i]);
}

int main(int argc, char const *argv[]){
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    dp.resize(n, -1);
    cout << SOLVE(n - 1);
    
    return 0;
}