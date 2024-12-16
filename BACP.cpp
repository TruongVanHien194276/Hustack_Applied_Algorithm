// Problem: BACP
// Description
// The BACP is to design a balanced academic curriculum by assigning periods to courses in a way that the academic load of each period is balanced. There are N courses 1, 2, …, N that must be assigned to M periods 1, 2, …, M. Each course i has credit ci and has some courses as prerequisites. The load of a period is defined to be the sum of credits of courses assigned to that period.
// The prerequisites information is represented by a matrix ANxN in which Ai,j = 1 indicates that course i must be assigned to a period before the period to which the course j is assigned. Compute the solution satisfying constraints: 
// Satisfy the prerequisites constraints: if Ai,j = 1, then course i must be
// assigned to a period before the period to which the course j is assigned
// The maximum load for all periods is minimal

// Input
// Line 1 contains N and M (2 ≤ N ≤16, 2 ≤ M ≤ 5)
// Line 2 contains c1, c2, …, cN
// Line i+2 (i = 1,…, N) contains the ith line of the matrix A

// Output
// Unique line contains that maximum load for all periods of the solution
// found
// Example
// Input
// 6 2
// 4 4 4 4 2 4 
// 0 0 0 0 0 0 
// 0 0 0 0 0 0 
// 0 0 0 0 0 0 
// 0 0 1 0 0 0 
// 0 0 1 0 0 0 
// 1 0 0 0 0 0

// Output
// 12

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MAX = 20;

int N, M;
int c[MAX];
vector<vector<int> > A;
int course[MAX];
int maxLoadAllPeriods = 0;
int minAll = INF;
int loadOfPeriods[MAX];

bool check(int a, int i){
    // Kiểm tra khóa học a, kì i
    for (int j = 0; j < A[a].size(); j++){
        if (course[A[a].at(j)] == i) return false;
    }
    return true;
}

void solution(){
    minAll = min(minAll, maxLoadAllPeriods);
}

void TRY(int a){
    for (int i = 0; i < M; i++){
        if (check(a, i)){
            course[a] = i; // Khóa học a chỉ định vào kì i
            loadOfPeriods[i] += c[a];
            int pre = maxLoadAllPeriods;
            maxLoadAllPeriods = max(maxLoadAllPeriods, loadOfPeriods[i]);

            if (a == N) solution();
            else{
                if (maxLoadAllPeriods < minAll) TRY(a+1);
            }

            maxLoadAllPeriods = pre;
            loadOfPeriods[i] -= c[a];
        }
    }
}

int main(int argc, const char** argv) {
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        cin >> c[i];
    }
    A.resize(N+1);

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int tmp;
            cin >> tmp;
            if (tmp != 0) A[j].push_back(i);
        }
    }

    TRY(0);
    cout << minAll;

    return 0;
}