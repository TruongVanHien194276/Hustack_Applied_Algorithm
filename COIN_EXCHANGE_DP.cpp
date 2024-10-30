// Problem: Coin Exchange DP
// Description
// Given a set of coins with denominations D1, D2, ..., Dn and a denomination x. Find the minimum number of coins to exchange for denomination x.
// Input
// Line 1: contains 2 positive integers n and x (1 <= n <= 1000, 1 <= x <= 1000)
// Line 2: contains n positive integers D1, D2, . . ., Dn

// Output
// Write the minimum number of coins used

// Example
// Input
// 4 10
// 2 1 1 3 
// Output
// 4

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MAX_N = 1010;
const int MAX_X = 1010;

int n, x;
int D[MAX_N];
int dp[MAX_X];

int MinCoin(){
    dp[0] = 0;
    for (int i = 1; i <= x; i++){
        dp[i] = INF;
        for (int j = 0; j < n; j++){
            if (i >= D[j]) dp[i] = min(dp[i], dp[i - D[j]] + 1);
        }
    }
    return dp[x];
}

int main(int argc, const char** argv) {
    cin >> n >> x;
    for (int i = 0; i < n; i++){
        cin >> D[i];
    }

    cout << MinCoin();

    return 0;
}

