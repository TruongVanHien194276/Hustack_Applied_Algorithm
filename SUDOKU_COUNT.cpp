// Problem: Count number of sudoku solutions
// Description
// Write a program to compute the number of sudoku solutions (fill the zero elements of a given partial sudoku table)
// Fill numbers from 1, 2, 3, .., 9 to 9 x 9 table so that:
// Numbers of each row are distinct
// Numbers of each column are distinct
// Numbers on each sub-square 3 x 3 are distinct
// Input
// Each line i (i = 1, 2, ..., 9) contains elements of the i
// th
//  row of the Sudoku table: elements are numbers from 0 to 9 (value 0 means the empty cell of the table)
// Output
// Write the number of solutions found

// Example
// Input
// 0 0 3 4 0 0 0 8 9
// 0 0 6 7 8 9 0 2 3
// 0 8 0 0 2 3 4 5 6
// 0 0 4 0 6 5 0 9 7
// 0 6 0 0 9 0 0 1 4
// 0 0 7 2 0 4 3 6 5
// 0 3 0 6 0 2 0 7 8
// 0 0 0 0 0 0 0 0 0
// 0 0 0 0 0 0 0 0 0
// Output
// 64

#include <bits/stdc++.h> 

using namespace std;

const int N = 9;

bool isValid(vector<vector<int> > board, int row, int col, int num) {
    for (int i = 0; i < N; i++) {
        if (board[row][i] == num) return false;
    }
    for (int i = 0; i < N; i++) {
        if (board[i][col] == num) return false;
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i + startRow][j + startCol] == num) return false;
        }
    }
    return true;
}

int Counting(vector<vector<int> > board, int row, int col) {
    if (row == N - 1 && col == N) return 1;
    
    if (col == N) {
        row++;
        col = 0;
    }
    
    if (board[row][col] != 0) return Counting(board, row, col + 1);

    int cnt = 0;
    for (int num = 1; num <= 9; num++) {
        if (isValid(board, row, col, num)) {
            board[row][col] = num;
            cnt += Counting(board, row, col + 1);
            board[row][col] = 0;
        }
    }
    
    return cnt;
}

int main(int argc, char const *argv[]){
    vector<vector<int> > board(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    cout << Counting(board, 0, 0) << endl;

    return 0;
}
