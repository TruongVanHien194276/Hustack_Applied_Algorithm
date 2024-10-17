// Problem: Chapter 4 - Job Selection & Planning
// Description
// Given n jobs J = {1,. . .,n}. Each job i has a deadline d(i) and associated profit p(i) if the job is finished before the deadline. Every job takes the single unit of time, so the minimum possible deadline for any job is 1. It is also noted that no more than one job can be executed at a time.
// Select and schedule a subset of jobs of J such that the total profits is maximal.
// Input
// Line 1: contains a positive integer n (1 <= n <= 10^5)
// Line i+1 (i=1,. . . ,n) contains d(i) and p(i) (1 <= d(i), p(i) <= 10^5)
// Output
// Write to total profits obtained from the subset of jobs found.

// Example
// Input
// 6
// 3 10
// 2 40
// 6 70
// 3 50
// 5 80
// 1 60
// Output
// 300

#include <bits/stdc++.h>

using namespace std;

const int N = 100010; 

int n;
vector<pair<int, int>> jobs(n);
bool timeSlots[N]; 

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second; 
}

int SOLVE() {
    sort(jobs.begin(), jobs.end(), cmp);

    int res = 0;
    for (auto u : jobs) {
        int deadline = u.first;
        int profit = u.second;

        for (int i = min(deadline, N); i > 0; i--) {
            if (!timeSlots[i]) {
                timeSlots[i] = true;
                res += profit;
                break;
            }
        }
    }

    return res; 
}

int main(int argc, char const *argv[]){
    cin >> n;

    jobs.resize(n);
    int d, p;
    for (int i = 0; i < n; i++) {
        cin >> d >> p;
        jobs[i] = make_pair(d, p);
    }

    cout << SOLVE(); 

    return 0;
}
