// Problem: Chapter 8 - Geometry - Check convex hull
// Description
// Given a sequence of n points on the plane (each point has an integer coordinate) P1(x1, y1), P2(x2,y2), . . ., Pn(xn,yn). Write a program to check if the given points form a convex hull.

// Input
// Line 1: contains a positive integer T which is the number of test case (1 <= T <= 20)
// Subsequent lines are testcase, each testcase has the folowwing format:
// Line 1: contains a positive integer n (3 <= n <= 500)
// Line i+1 (i = 1, 2, ..., n): contains 2 integers xi, yi (-1000 <= xi,yi <= 1000) 

// Output
// Line t (t = 1, 2, ..., T): contains 1 if the answer of the tth testcase is YES and contains 0, otherwise.


// Example
// Input 
// 2
// 5
// 5 6
// 2 5
// 3 7
// 5 3
// 8 7
// 4
// 2 5
// 5 3
// 8 7
// 3 7

// Output 
// 0
// 1

#include <bits/stdc++.h>

using namespace std;
using Point = pair<int, int>;

vector<Point> vt;

int cross(const Point &O, const Point &A, const Point &B) {
    return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
}

bool isConvexHull(const vector<Point> &vt) {
    int n = vt.size();
    if (n < 3) return false;

    bool pos = false, neg = false;
    for (int i = 0; i < n; i++) {
        int pro = cross(vt[i], vt[(i + 1) % n], vt[(i + 2) % n]);
        if (pro > 0) pos = true;
        if (pro < 0) neg = true;
        if (pos && neg) return false;
    }
    return true;
}

int main(int argc, char const *argv[]){
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vt.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> vt[i].first >> vt[i].second;
        }

        cout << (isConvexHull(vt) ? 1 : 0) << endl;
    }
    return 0;
}
