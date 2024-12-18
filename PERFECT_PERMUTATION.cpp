// Problem: Perfect Permutation
// Description
// Let the set N = {1,2,3,...,n}. Each n element permutation of the set N is represented by the array a[1], a[2],...,a[n].
// An n element permutation of the set N is perfect if each element a[i] in the permutation satisfies one of the following two conditions:
// 1. a[i] is divisied by i 
// 2. i is divisible by a[i]

// Input: A positive number n (1 ≤ n ≤ 15)
// Output: The number of perfect permutations including n elements created from the set N = {1, 2, ..., n}

#include <bits/stdc++.h>

using namespace std;

int n;
int cnt = 0;
vector<int> a;
vector<bool> used;

void TRY(int v) {
    if (v == n) { 
        cnt += 1; 
        return; 
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i]) { 
            if (i % (v + 1) == 0 || (v + 1) % i == 0) { 
                a[v] = i; 
                used[i] = true; 
                TRY(v + 1);
                used[i] = false; 
            }
        }
    }
}

int main(int argc, char const *argv[]){
    cin >> n;
    a.resize(n);
    used.assign(n + 1, false); 

    TRY(0);
    cout << cnt;

    return 0;
}
