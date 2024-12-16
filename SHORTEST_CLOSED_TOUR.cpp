// Problem: Shortest Closed Tour
// Given n points 1, 2, ..., n in which d(i,j) is the distance from point i to point j (i,j = 1,...,n).
// We need to create a tour starting from one point, then visiting all the remaining points and terminating at the starting point.
// Let P be the set containing precedence pairs of points (xi, yi) such that point xi must be visitedited before point y0 in the tour (xi, yi in {1,...,n}).
// Find the shortest closed tour so that the total travel distance is minimal.

// Input:
// Line 1: a natural number n, which in the number of points (1 ≤ n ≤ 200)
// Line i+1 (i = 1,...,n): n natural numbers separated by spaces, where the jth number is the distance from point i to point j (j = 1,...,n)
// Line n+2: a natural number P, which is the number of precedence pairs
// Line n+2+i (i = 1,...,P): 2 natural numbers xi and yi, separated by spaces

// Output:
// Line 1: the number of points in the best solution
// Line 2: the sequence of points in the best solution


// Example:
// Input:
// 5
// 0 1 2 3 4
// 3 0 2 4 5
// 1 3 0 4 2
// 4 2 1 0 3
// 2 3 4 1 0
// 2
// 2 4
// 2 1

// Output:
// 5 
// 2 3 1 5 4

#include <bits/stdc++.h>

using namespace std;

const int MAX = 210;
const int INF = 1e9;

int m, n;
vector<int> visited(MAX);
vector<vector<int>> c(MAX, vector<int>(MAX)), g(MAX, vector<int>(MAX));
vector<int> deg_in(MAX), ver(MAX), path(MAX);
int num_ver, totalCost = 0;
int minCost = INF;

bool checkTopo(int u) {
    for (int i = 1; i <= n; i++) {
        if (g[i][u] && !visited[i]) return false;
    }
    return true;
}

void DFS(int u) {
    int v_min = 0;
    ver[++num_ver] = u;
    visited[u] = 1;

    for (int i = 1; i <= n; i++) {
        if (visited[i] || !checkTopo(i)) continue;
        if (!v_min || c[u][i] < c[u][v_min]) v_min = i;
    }

    if (v_min != 0 && num_ver != n) {
        totalCost += c[u][v_min];
        DFS(v_min);
    }
}

int main(int argc, char const *argv[]){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    cin >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        g[x][y] = 1;
        deg_in[y]++;
    }

    for (int i = 1; i <= m; i++) {
        if (!deg_in[i]) { 
            totalCost = 0, num_ver = 0;
            visited.assign(MAX, 0);
            DFS(i);
            totalCost += c[ver[n]][i];
            if (totalCost < minCost) {
                minCost = totalCost;
                for (int i = 1; i <= n; i++) {
                    path[i] = ver[i];
                }
            }
        }
    }

    cout << n << endl;
    for (int i = 1; i <= n; i++){
        cout << path[i] << " ";
    }
    return 0;
}