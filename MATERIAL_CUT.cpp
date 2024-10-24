// Problem: Chapter 3 - Cut Material
// Description
// Given a material having the shape rectangle with height H and width W. We need to cut this material into n smaller rectangle submaterials of size (h1,w1), (h2, w2), ..., (hn, wn). Write a program to check if we can perform this cut.
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

const int N = 15;

int H, W, n;
int h[N], w[N];
int mark[N][N]; 

bool check(int x, int y, int k, int type){
    int ah = h[k], aw = w[k];

    if (type == 1) swap(ah, aw);
    if (x + ah - 1 > H || y + aw - 1 > W) return false;

    for (int i = x; i <= x + ah - 1; i++){
        for (int j = y; j <= y + aw - 1; j++){
            if (mark[i][j]) return false;
        }
    }
    return true;
}

void doMark(int x, int y, int k , int type, int mark_value){
    int ah = h[k], aw = w[k];
    if (type == 1) swap(ah, aw);
    for (int i = x; i <= x + ah - 1; i++){
        for(int j = y; j <= y + aw - 1; j++){
            mark[i][j] = mark_value;
        }
    }

}

void TRY(int k) {
    for (int i = 1; i <= H; i++){
        for (int j = 1; j <= W; j++){
            for (int type = 0; type <= 1; type++) {
                if (check(i, j , k, type)) {
                    doMark(i, j , k , type, 1);
                    
                    if (k == n) {
                        cout << 1;
                        exit(0);
                    } else TRY(k + 1);

                    doMark(i, j, k, type, 0);
                }
            }
        }
    }
}

int main(int argc, char const *argv[]){
    cin >> H >> W >> n;
    for(int i = 1; i <= n; i++){
        cin >> h[i] >> w[i];
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            mark[i][j] = 0;
        }
    }

    TRY(1);
    cout << 0;

    return 0;
}