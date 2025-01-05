// Problem: SUM TRIPLE EQUAL Q
// Description
// Given a sequence of distinct integers a1, a2, . . ., an and an integer value Q. 
// Compute the number P of triples (i, j, k) such that 1 <= i < j < k <= n and ai + aj + ak = Q.

// Input
// Line 1: contains 2 integers n and Q (1 <= n <= 5000, 1 <= Q <= 1000000)
// Line 2: contains n integers a1, a2, . . ., an (1 <= ai <= 100000)

// Output
// Write the value P mod 10^9+7

// Example
// Input 
// 6 10
// 2 1 6 7 4 5

// Output 
// 2 

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int Counting(vector<int> a, int Q) {
    int n = a.size();
    int cnt = 0;

    sort(a.begin(), a.end());

    for (int i = 0; i < n - 2; i++) {
        int tmp = Q - a[i];
        int left = i + 1, right = n - 1;

        while (left < right) {
            int sum = a[left] + a[right];
            if (sum == tmp) {
                cnt++;
                cnt %= MOD;
                left++;
                right--; 
            } else if (sum < tmp) left++;
            else right--;
        }
    }
    return cnt;
}

int main(int argc, char const *argv[]){
    int n, Q;
    cin >> n >> Q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << Counting(a, Q);

    return 0;
}
