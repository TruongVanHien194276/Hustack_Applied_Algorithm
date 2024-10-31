// Problem: LAB.03.03 - Max-Distance Sub-Sequence
// Description
// Given N elements (2≤ N ≤100,000) on a straight line at positions x1,…, xN (0≤ xi ≤1,000,000,000).
// The distance of a subset of N elements is defined to be the minimum distance between two elements.
// Find the subset of N given elements containing exactly C elements such that the distance is maximal.
// Input
// The first line contains a positive integer T (1 <= T <= 20) which is the number of test cases. 
// Subsequent lines are T test cases with the following format:
// Line 1: Two space-separated integers: N and C
// Lines 2: contains  x1, x2, . . . , xN

// Output
// For each test case output one integer: the distance of the subset found.

// Example
// input
// 1
// 5 3
// 1
// 2
// 8
// 4
// 9
// output
// 3

// Explain: Jonh can put his 3 cows in the stalls at positions 1, 4 and 8, resulting in a minimum distance of 3.

#include <bits/stdc++.h>

using namespace std;

bool check(vector<int>& x, int N, int C, int dis) {
    int cnt = 1; 
    int last = x[0];

    for (int i = 1; i < N; i++) {
        if (x[i] - last >= dis) {
            cnt++;
            last = x[i];
            if (cnt == C) return true;
        }
    }
    return false;
}

int maxDis(vector<int>& x, int N, int C) {
    int left = 1; 
    int right = x[N - 1] - x[0]; 
    int res = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (check(x, N, C, mid)) {
            res = mid; 
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    return res;
}

int main(int argc, char const *argv[]){
    int T;
    cin >> T;

    while (T--) {
        int N, C;
        cin >> N >> C;

        vector<int> x(N);
        for (int i = 0; i < N; i++) {
            cin >> x[i];
        }

        sort(x.begin(), x.end());

        cout << maxDis(x, N, C) << endl;
    }

    return 0;
}
