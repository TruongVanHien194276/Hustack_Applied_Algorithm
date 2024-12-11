// Problem: LAB.05.05 - Make Span Schedule
// Description
// A project has n tasks 1,. . ., n. Task i has d d(i) to be completed (i=1,. . ., n). There are precedence constraints between tasks represented by a set Q of pairs: for each (i,j)  in Q, task j cannot be started before the completion of task i. Compute the earliest completion time  of the project.
// Input
// Line 1: contains n and m (1 <= n <= 10^4, 1 <= m <= 200000)
// Line 2: contains d(1),. . ., d(n) (1 <= d(i) <= 1000)
// Line i+3 (i=1,. . ., m) : contains i and j : task j cannot be started to execute before the completion of task i
// Output
// Write the earliest completion time of the project.
// Example
// Input
// 9 13
// 5 3 1 2 6 4 3 1 4
// 1 3
// 1 5
// 1 6
// 2 1
// 2 3
// 3 5
// 4 1
// 4 2
// 4 6
// 5 8
// 7 9
// 9 5
// 9 8

// Output
// 18

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    int n, m;
    cin >> n >> m;

    vector<int> d(n + 1);        
    vector<vector<int> > Graph(n + 1);    
    vector<int> degree(n + 1, 0);   
    vector<int> earliest(n + 1, 0);     

    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        degree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (degree[i] == 0) {
            q.push(i);  
            earliest[i] = 0;
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : Graph[u]) {
            earliest[v] = max(earliest[v], earliest[u] + d[u]);
            degree[v]--;

            if (degree[v] == 0) q.push(v);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, earliest[i] + d[i]);
    }

    cout << res;

    return 0;
}
