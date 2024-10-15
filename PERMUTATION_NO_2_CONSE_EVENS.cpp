// Problem: Generate permutations no 2 consecutive even elements
// Description
// Write a program that generates all permutations of 1, 2, ..., n in a lexicographic order such that there are no 2 consecutive even elements.
// Input
// A line contains a positive integer n (2 <= n <= 9)
// Output
// Each line contains a permutation, elements a re separated by a SPACE character
// Example
// Input
// 4
// Output
// 1 2 3 4
// 1 4 3 2
// 2 1 3 4
// 2 1 4 3
// 2 3 1 4
// 2 3 4 1
// 3 2 1 4
// 3 4 1 2
// 4 1 2 3
// 4 1 3 2
// 4 3 1 2
// 4 3 2 1

#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> a;       
vector<bool> used;  

void print() {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void TRY(int x) {
    if (x == n) {
        print();
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) {
            if (x == 0 || (x > 0 && !(a[x-1] % 2 == 0 && i % 2 == 0))) {
                a[x] = i;      
                used[i] = true; 

                TRY(x + 1);    

                used[i] = false; 
            }
        }
    }
}

int main(int argc, char const *argv[]){
    cin >> n;
    
    a.resize(n);
    used.resize(n + 1, false); 

    TRY(0);

    return 0;
}
