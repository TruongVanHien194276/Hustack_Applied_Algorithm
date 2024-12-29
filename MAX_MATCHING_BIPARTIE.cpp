// Problem: Chapter 5 - Max Matching on Bipartie Graph
// Description
// There are  n tasks 1,. . .,n and m staffs 1, . . , m. T(i) is the set of staffs that can perform the task i (i=1, . . ., n). Compute an assignment of staffs to tasks such that each task is assigned to at most one staff and each staff cannot be assigned to more than one task and the number of tasks assigned is maximal.
// Input
// Line 1: contains 2 positive integer n và m (1 <=  n,m <= 10000)
// Line i+1 (i=1, . . .,n) contains a positive integer k and k integer of T(i)
// Output
// Write the maximum number of tasks that are assigned to staffs.
// Example
// Input
// 3 4
// 2 1 4
// 2 1 3
// 1 2

// Output
// 3

#include <bits/stdc++.h>

using namespace std;

const int MAX = 10010;
const int INF = 1e9;

vector<int> Graph[MAX];
int pairU[MAX], pairV[MAX], d[MAX];
int n, m;

bool BFS() {
    queue<int> q;
    for (int u = 1; u <= n; u++) {
        if (pairU[u] == 0) {
            d[u] = 0;
            q.push(u);
        } else d[u] = INF;
    }
    d[0] = INF;

    while (!q.empty()) {
        int u = q.front(); q.pop();

        if (d[u] < d[0]) {
            for (int v : Graph[u]) {
                if (d[pairV[v]] == INF) {
                    d[pairV[v]] = d[u] + 1;
                    q.push(pairV[v]);
                }
            }
        }
    }

    return d[0] != INF;
}

bool DFS(int u) {
    if (u != 0) {
        for (int v : Graph[u]) {
            if (d[pairV[v]] == d[u] + 1) {
                if (DFS(pairV[v])) {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        d[u] = INF;
        return false;
    }
    return true;
}

int hopcroftKarp() {
    memset(pairU, 0, sizeof(pairU));
    memset(pairV, 0, sizeof(pairV));
    int cnt = 0;

    while (BFS()) {
        for (int u = 1; u <= n; u++) {
            if (pairU[u] == 0 && DFS(u)) cnt++;
        }
    }

    return cnt;
}

int main(int argc, char const *argv[]){
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        while (k--) {
            int x;
            cin >> x;
            Graph[i].push_back(x);
        }
    }

    cout << hopcroftKarp();

    return 0;
}
