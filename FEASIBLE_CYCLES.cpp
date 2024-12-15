// Problem: Feasible Cycles
// Given n points on a plane, each point i has coordinates x[i] and y[i], count the number of cycles that start from a point, visit all the (n-1) other points exactly once, and return to the starting point, such that the total distance of the cycle is less than or equal to a given number L. 
// Note that, the distance from point i to point j is the Manhattan distance |x[i] - x[j]| + |y[i] - y[j]|.

// Input:
// Line 1: Integer n (1 ≤ n ≤ 10)
// Line i+1: Contains two integers, separated by a space, for the coordinates (x[i] and y[i]) of point i (0 ≤ x[i], y[i] ≤ 100)
// Line n+1: Integer L (1 ≤ L ≤ 100000)

// Output: One integer for the number of feasible cycles

// Example:
// Input:
// 5
// 41 67
// 34 0
// 69 24
// 78 58
// 62 64
// 222

// Output: 2

#include <bits/stdc++.h>

using namespace std;

int n, L;
vector<pair<int, int> > a;
vector<bool> visited;

int dis(pair<int, int> p1, pair<int, int> p2) {
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int Counting(int cur, int cntVisited, int total) {
    if (cntVisited == n) {
        total += dis(a[cur], a[0]);
        return (total <= L) ? 1 : 0;
    }

    int cnt = 0;
    for (int i = 1; i < n; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            cnt += Counting(i, cntVisited + 1, total + dis(a[cur], a[i]));
            visited[i] = false;
        }
    }
    return cnt;
}

int solve() {
    visited.assign(n, false);
    visited[0] = true;
    return Counting(0, 1, 0);
}

int main() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    cin >> L;

    cout << solve();
    return 0;
}
