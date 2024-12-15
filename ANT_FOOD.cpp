// Problem: Ant food
// You are given a cylindrical tube that, when flattened, forms an MxN grid of cells. Each cell at row i column j (denote as (i, j)) in the grid contains a certain amount of food. 
// An ant starts from any cell on the left edge of the cylinder (i.e., the first column of grid) and crawls to the right edge (i.e., the last column of grid). 
// From a cell (i, j), the ant can move to one of the following three cells: (i-1,j+1), (i,j+1), (i+1,j+1). 
// Due to the cylindrical nature of the tube, the ant can wrap around from the top row to the bottom row and vice versa (i.e., if the ant moves up from the top row, it wraps around to the bottom row; and if the ant moves down from the bottom row, it wraps around to the top row). 
// The objective is to determine the path that allows the ant to collect the maximum amount of food as it travels from the left edge to the right edge of the grid.


// Input:
// Line 1: 2 positive integers M and N separated by a space, respectively represent the number of rows and columns of the gird (1 ≤ M, N ≤ 1000)
// Line i+1 (i = 1,...,M): N non negative integers with vaalues in the range [0, 500] sepaareted by spaces, where jth number corrresponds to the amount of food in the cell at row i and column j (j = 1,...,N)

// Output: An integer representing the maximum amount of food the ant can collect

// Example:
// Input:
// 4 4
// 1 3 1 5
// 2 2 4 1
// 5 0 2 3
// 0 6 1 2

// Output: 17

#include <bits/stdc++.h>

using namespace std;

int M, N;
vector<vector<int> > a, dp;

int maxFunc(int a, int b, int c) {
    return max(a, max(b, c));
}

int main() {
    cin >> M >> N;
    a.assign(M, vector<int>(N));
    dp.assign(M, vector<int>(N, 0));

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        dp[i][0] = a[i][0];
    }

    for (int j = 1; j < N; j++) {
        for (int i = 0; i < M; i++) {
            int x = dp[(i-1+M)%M][j-1];
            int y = dp[i][j-1];
            int z = dp[(i+1)%M][j-1];
            dp[i][j] = a[i][j] + maxFunc(x, y, z);
        }
    }

    int res = 0;
    for (int i = 0; i < M; i++){
        res = max(res, dp[i][N-1]);
    }
    cout << res;

    return 0;
}
