// Problem: Total Revenue
// The revenue of a shop on day i is a[i] (i = 1, 2,.. ,, n). 
// Given a positive integer K, a K-period is a subsequence of K consecutive days of 1, 2,..., n. 
// Given a threshold D (positive integer), compute the number Q of K-periods in which the total revenue is greater than or equal to D.

// Input:
// Line 1: contains 3 positive integers n, K and D (1 ≤ n ≤ 100000, 1 ≤ K ≤ n/2, 1 ≤ D ≤ 1000000)
// Line 2: contains n integers a[1], a[2],.. ., a[n] (1 ≤ a[i] ≤ 10000)

// Output: Write the value Q.

// Example
// Input
// 7 3 10
// 6 3 4 2 3 3 5

// Output
// 2

// Explanation: 
// Revenues of two 3-periods below satisfy the constrainst:
// 6 3 4
// 3 3 5

#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, K, D; 
    cin >> n >> K >> D;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int Q = 0; 
    int s = 0;
    for (int i = 0; i < K; i++) {
        s += a[i];
    }

    if (s >= D) Q += 1;

    for (int i = K; i < n; i++) {
        s += a[i];      
        s -= a[i - K];  
        if (s >= D) Q+= 1;
    }

    cout << Q;
    return 0;
}
