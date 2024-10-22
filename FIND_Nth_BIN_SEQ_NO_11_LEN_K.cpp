// Problem: The nth binary sequence of length k does not contain 11
// Description
// Given a positive integer k, let L be the list of binary sequence of length k containing no 11 
// (sequences are sorted in a lexicographic order).
// Given a positive integer n, find the nth sequence in L.

// Input
// Line 1: contains k and n (1 <= k <= 50, 1 <= n <= 1000000000)

// Output
// Write the sequence found, or write -1 if the sequence does not exist.

// Example
// Input
// 5 3
// Output 
// 00010


// Input
// 5 100
// Output 
// -1

// Input
// 30 100000
// Output 
// 000000100101000001001001010100

#include<bits/stdc++.h>

using namespace std;

const int N = 55;

long long n, f[N][2];
int k;

void TRY(int p, int pre_number) {
    if(p == 0) 
        return;

    if (pre_number == 1) {
        cout << 0;
        TRY(p - 1, 0);
        return;
    }

    if (n > f[p][0]) {
        cout << 1;
        n -= f[p][0];
        TRY(p - 1, 1);
    } else {
        cout << 0;
        TRY(p - 1, 0);
    }
}

int main(int argc, char const *argv[]){
    cin >> k >> n;

    f[0][0] = 1;
    f[0][1] = 0;
    for (int i = 1; i <= k; i++) {
        f[i][0] = f[i - 1][0] + f[i - 1][1];
        f[i][1] = f[i - 1][0];    
    }

    if (n > max(f[k][0], f[k][1])) cout << -1;
    else TRY(k, 0);

    return 0;
}