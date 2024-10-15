// Problem: Generate binary sequences without 111
// Description
// Write a program that generates all binary sequence of length n that do not contains 111.
// Input
// Line 1: contains a positive integer n 

// Output
// Write in each line a binary sequence containing no 111 (the sequences are listed in a lexicographic order)

// Example
// Input 
// 3

// Output 
// 000
// 001
// 010
// 011
// 100
// 101
// 110

// Input 
// 4

// Output 
// 0000
// 0001
// 0010
// 0011
// 0100
// 0101
// 0110
// 1000
// 1001
// 1010
// 1011
// 1100
// 1101

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;

void print() {
    for (int i = 0; i < n; i++) {
        cout << a[i];
    }
    cout << endl;
}

void TRY(int x) {
    for (int i = 0; i <= 1; i++) {
        a[x] = i;
        if (x < 2 || !(a[x] == 1 && a[x-1] == 1 && a[x-2] == 1)) {
            if (x == n-1) print();
            else TRY(x+1);
        }
    }
}

int main(int argc, char const *argv[]) {
    cin >> n;
    a.resize(n);

    TRY(0);

    return 0;
}

