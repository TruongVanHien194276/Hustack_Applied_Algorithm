// Problem: 3 Disjoint subsequences max
// Description
// Given a sequence of n integers a[1], a[2], . . ., a[n]. A subsequence is defined to be a sequence of consecutive elements a[i], a[i+1], . . ., a[j].
// Find 3 subsequences of the given sequence such that the sum of elements of these 3 subsequences is maximal.
// Input
// Line 1: contains a positive integers n (5 <= n <= 10000)
// Line 2: contains a[1], a[2], . . ., a[n] (-1000 <= a[i] <= 1000)

// Output
// Write the sum of elememts of the 3 subsequences found.

// Example
// Input
// 8
// 3 2 -8 4 5 -10 6 13

// Output
// 33

#include <bits/stdc++.h>

using namespace std;

const int NEG_INF = -1e9;

vector<int> a;
vector<int> dp_prefix, dp_suffix;
int n;

int SOLVE() {
    int s = 0, max_sum = NEG_INF;
    for (int i = 0; i < n; i++) {
        s = max(a[i], s + a[i]);  
        max_sum = max(max_sum, s);
        dp_prefix[i] = max_sum;
    }

    s = 0, max_sum = NEG_INF;
    for (int i = n - 1; i >= 0; i--) {
        s = max(a[i], s + a[i]);  
        max_sum = max(max_sum, s);
        dp_suffix[i] = max_sum;
    }

    int res = NEG_INF;
    for (int i = 1; i < n - 1; i++) {
        s = 0;
        max_sum = NEG_INF;

        for (int j = i; j < n - 1; j++) {
            s = max(a[j], s + a[j]);  
            max_sum = max(max_sum, s);

            res = max(res, dp_prefix[i - 1] + max_sum + dp_suffix[j + 1]);
        }
    }

    return res;
}

int main(int argc, char const *argv[]){
    cin >> n;
    a.resize(n);
    dp_prefix.resize(n);
    dp_suffix.resize(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    cout << SOLVE();

    return 0;
}
