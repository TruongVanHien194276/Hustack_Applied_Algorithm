// Problem: Chapter 8 - Geometry check points inside convex hull
// Description
// Given a sequence of points P1, P2, ...,  Pn. Given K point T1, T2, ..., Tk. Write a program to check if P1, P2, . . ., Pn form a convex hull C and the points Ti (i = 1,...,K) is inside the convex hull C.

// Input
// Line 1: contains a positive integer n (3 <= n <= 10000)
// Line i+1 (i = 1, 2, ..., n): contains 2 integer xi, yi which are x,y-coordinate of point Pi (-1000 <= xi,yi <= 1000)
// Line n+2: contains apositive integer K (1 <= K <= 100000)
// Line k+n+2 (k= 1, 2, ..., K): contains 2 integer xk, yk which are x,y-coordiate of Tk (-1000 <= xk, yk <= 1000)

// Output
// Line k writes 1 if P1, ..., Pn forms a convex hull and point Tk is  inside that convex hull, and writes 0, otherwise. 

// Example
// Input 
// 4
// 5 6
// 3 7
// 2 5
// 5 3
// 4
// 8 7
// 4 5
// 3 7
// 0 0 

// Output 
// 0
// 1
// 1
// 0

#include <bits/stdc++.h>

using namespace std;

struct Point {
    int x, y;
    
    bool operator < (const Point& p) const {
        if (x != p.x) return x < p.x;
        return y < p.y;
    }
};

int cross(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.x - p1.x) * (p3.y - p1.y) - (p2.y - p1.y) * (p3.x - p1.x);
}

vector<Point> convexHull(vector<Point>& vt) {
    sort(vt.begin(), vt.end()); 

    vector<Point> lower, upper;

    for (const Point& p : vt) {
        while (lower.size() >= 2 && cross(lower[lower.size() - 2], lower[lower.size() - 1], p) <= 0) {
            lower.pop_back();
        }
        lower.push_back(p);
    }

    for (int i = vt.size() - 1; i >= 0; i--) {
        while (upper.size() >= 2 && cross(upper[upper.size() - 2], upper[upper.size() - 1], vt[i]) <= 0) {
            upper.pop_back();
        }
        upper.push_back(vt[i]);
    }

    lower.pop_back();
    upper.pop_back();

    lower.insert(lower.end(), upper.begin(), upper.end());

    return lower;
}

bool checkInside(vector<Point>& hull, Point& q) {
    int n = hull.size();
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        if (cross(hull[i], hull[j], q) < 0) 
            return false;
    }
    return true;
}

int main(int argc, char const *argv[]){
    int n, K;
    cin >> n;

    vector<Point> vt(n);
    for (int i = 0; i < n; i++) {
        cin >> vt[i].x >> vt[i].y;
    }

    vector<Point> hull = convexHull(vt);

    cin >> K;
    for (int i = 0; i < K; i++) {
        Point q;
        cin >> q.x >> q.y;

        if (checkInside(hull, q)) cout << "1" << endl;
        else cout << "0" << endl;
    }

    return 0;
}
