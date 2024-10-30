// Problem: Longest Increasing Subsequence (Hard)
// Description
// Given a sequence a of positive a1, a2, . . ., an. A subsequence of a is defined to be the sequence obtained by removing some elements. Find the subsequence of a such that the elements is in an increasing order and the number of elements of the subsequence is maximal.
// Input
// Line 1: contains a positive integer n (1 <= n <= 100000)
// Line 2: contains n elements of the given sequence (1 <= ai <= 100000)
// Output
// The length of the subsequence found.
// Example
// Input
// 6
// 5 8 2 8 10 10
// Output
// 3

// #include <bits/stdc++.h>

// using namespace std;

// const int MAX = 100010;

// int n, a[MAX], S[MAX];

// int SOLVE(){
//     S[0] = 1;
//     int res = S[0];
//     for (int i = 1; i < n-1; i++){
//         S[i] = 1;
//         for (int j = 0; j < i; j++){
//             if (a[i] > a[j]){
//                 if (S[i] < S[j] + 1) S[i] = S[j] + 1;
//             }
//         }
//         res = max(res, S[i]);
//     }
//     return res;
// }

// int main(int argc, const char** argv) {
//     cin >> n;
//     for (int i = 0; i < n; i++){
//         cin >> a[i];
//     }

//     cout << SOLVE();

//     return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp; 
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(dp.begin(), dp.end(), a[i]);
        
        if (it == dp.end()) dp.push_back(a[i]);
        else *it = a[i];
    }

    cout << dp.size();

    return 0;
}
