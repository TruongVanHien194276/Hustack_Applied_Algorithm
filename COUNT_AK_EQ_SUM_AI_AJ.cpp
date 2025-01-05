// Problem: Count AK = AI + AJ
// Description
// Given a sequence of distinct integers a1, a2, . . ., an. 
// Compute the number P of triples of distinct indices (i, j, k) such that among 3 items ai, aj, ak there is an item which is equal to the sum of 2 remaining items. 

// Input
// Line 1: contains an integer n (1 <= n <= 2000)
// Line 2: contains n integers a1, a2, . . ., an (1 <= ai <= 100000)

// Output
// Write the value P mod 10^9+7

// Example
// Input 
// 6
// 1 3 4 5 8 9

// Output 
// 5

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

int Counting(vector<int> a) {
    int n = a.size();
    int cnt = 0;
    sort(a.begin(), a.end());

    for (int k = 2; k < n; k++) {
        int i = 0, j = k - 1;
        while (i < j) {
            if (a[i] + a[j] == a[k]) {
                cnt++;
                cnt %= MOD;
                i++;
                j--;
            } else if (a[i] + a[j] < a[k]) i++;
            else j--;
        }
    }
    return cnt;
}

int main(int argc, char const *argv[]){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    cout << Counting(a);

    return 0;
}
