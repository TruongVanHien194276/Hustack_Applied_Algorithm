// Problem: Chapter 4 - Parallel Job Execution
// Description
// There are n jobs 1, 2, . . ., n that must be executed. Job i has the duration d[i]: if job i starts at time-point t, then it finishes at time-point t+d[i]. At any time-point, at most one job can start to execute. Find the schedule (specify the time-point for starting each job) for executing all n given jobs so that completion time T (all jobs finish before or at T) is minimal (starting time-point is 0).

// Input
// Line 1: contains a positive integer n (1 <= n <= 100000)
// Line 2: contains n positive integers d[1], d[2], ..., d[n] (1 <= d[i] <= 1000000)

// Output
// Write T 

// Example
// Input
// 5
// 3 7 4 9 1

// Output 
// 9

// Explanation
// Job 1 starts at time-point 3 and finishes at time-point 6
// Job 2 starts at time-point 1 and finishes at time-point 8
// Job 3 starts at time-point 2 and finishes at time-point 6
// Job 4 starts at time-point 0 and finishes at time-point 9 
// Job 5 starts at time-point 4 and finishes at time-point 5

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, d[N];
int res = 0;

int main(int argc, char const *argv[]){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> d[i];
    }
    
    sort(d, d + n, greater<int>());
    for(int i = 0; i < n; i++){
        res = max(res, d[i] + i);
    }
    cout << res;

    return 0;
}