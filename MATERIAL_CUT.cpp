// Problem: Chapter 3 - Cut Material
// Description
// Given a material having the shape rectangle with height H and width W. We need to cut this material into n smaller rectangle rect of size (h1,w1), (h2, w2), ..., (hn, wn). Write a program to check if we can perform this cut.
// Input
// Line 1: contains two positive integers H, W (1 <= H, W <= 10)
// Line 2: contains a positive integer n (1 <= n <= 10)
// Line i+2 (i= 1,...,n): contains two positive integer hi and wi (1 <= hi, wi <= 10)
// Output
// Write 1 if we can perform the cut and write 0, otherwise.
// Example
// Input
// 7 5
// 4
// 1 5
// 6 2
// 2 2
// 4 3
// Output
// 1

#include <bits/stdc++.h>

using namespace std;

int H, W, n;
int h[11], w[11];

bool check() {
    int total_area = 0;
    int HW = max(H, W);
    for (int i = 0; i < n; i++) {
        if (h[i] > HW || w[i] > W) return false;
        total_area += h[i] * w[i];
    }
    return total_area <= H * W;
}

int main(int argc, char const *argv[]){
    cin >> H >> W >> n;
    for (int i = 0; i < n; i++){
        cin >> h[i] >> w[i];
    }

    cout << check();
    return 0;
}
