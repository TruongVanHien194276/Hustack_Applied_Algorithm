// Problem: Count Successful Participants
// The result of an exam is represented by the sequence of integers a[1], a[2],.. ., a[v] in which a[i] is the point of the participant i (i = 1,..., n). 
// Given a threshold D (which is a positive integer), a participant i is considered to be successful if his result a[i] is greater or equal to D. Count the number of successful participants.

// Input:
// Line 1: contains 2 positive integers n and D (1 ≤ n, D ≤ 1000)
// Line 2: contains a[1], a[2],.. ., a[n] (1 ≤ a[i] ≤ 1000)    

// Output: Write the number of successful participants.

// Example
// Input
// 5 4
// 3 2 0 8 4

// Output
// 2

#include < bits/stdc++.h 

using namespace std;

int main(int argc, char const *argv[]){
    int n, D; 
    cin >> n >> D;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] >= D) cnt += 1;
    }

    cout << cnt;
    return 0;
}
