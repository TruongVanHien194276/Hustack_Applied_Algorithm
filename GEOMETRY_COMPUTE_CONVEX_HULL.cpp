// Problem: Chapter 8 - Geometry Find Convex Hull
// Description
// Given a set of points P1, P2, ..., Pn on the plane: point Pi has coordinate (xi,yi).
// Compute the convex hull of the given points: The convex hull is a subset of the given points that forms a convex polygon that contains all the given points.

// Input
// Line 1: contains a positive integer n (3 <= n <= 100000)
// Line i+1 (i = 1, 2, ..., n): contains 2 integers xi, yi (-1000 <= xi, yi <= 1000)

// Output 
// Line 1: writes the number of points of the convex hull found 
// Subsequent lines, each line contains 2 integers which are the x-coordinate and y-coordinate of a point of the convex hull found 

// Example 
// Input 
// 6
// 4 5
// 5 3
// 5 6
// 2 5
// 8 7
// 3 7

// Output
// 4
// 5 3
// 8 7
// 3 7
// 2 5 

#include <bits/stdc++.h>

using namespace std;
using Point = pair<int, int>;

vector<Point> vt;
vector<Point> hull;

int cross(const Point &p1, const Point &p2, const Point &p3) {
    return (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);
}

void convexHull() {
    int n = vt.size();
    if (n <= 1) {
        hull = vt;
        return;
    }

    sort(vt.begin(), vt.end());
    for (const auto &p : vt) {
        while (hull.size() >= 2 && cross(hull[hull.size()-2], hull[hull.size()-1], p) <= 0) {
            hull.pop_back();
        }
        hull.push_back(p);
    }

    size_t low = hull.size();
    for (int i = n - 2; i >= 0; i--) {
        while (hull.size() > low && cross(hull[hull.size()-2], hull[hull.size()-1], vt[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(vt[i]);
    }

    hull.pop_back(); 
}

int main(int argc, char const *argv[]){
    int n;
    cin >> n;
    vt.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> vt[i].first >> vt[i].second;
    }

    convexHull();

    cout << hull.size() << endl;
    for (const auto &p : hull) {
        cout << p.first << " " << p.second << endl;
    }

    return 0;
}