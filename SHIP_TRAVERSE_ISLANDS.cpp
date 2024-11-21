// Problem: Ship traversing islands in an ocean
// Description
// There are n islands 1, 2, ..., n in the ocean. The island i has coordinate x[i],y[i]. A ship departs from the island 1 and wants to go to the island n. Due the limited capacity of the Bin of fuel,  the ship cannot travel from island the i to the island j if the distance between i and j is more than D. On each island, there is a resource for load fuel until the Bin is full. An itinerary of length k of the Ship is the sequence of islands i1, i2, ..., i k+1
//  in which i1 = 1 and i k+1 = n and the distance between i_j and i_j+1 is less than or equal to D. 
// Find the way for the Ship to traverse from island 1 to the island n with minimum length.
// Input
// Line 1: contains n and D (1 <= n <= 10000, 1 <= D <= 10000)
// Line i+1 (i = 1, 2, ..., n): contains 2 integers x[i] and y[i] (0 <= x[i], y[i] <= 10000)

// Output
// Write the length of the itinerary found or write -1 if no itinerary exists.

// Example
// Input 
// 8 4
// 6 0
// 3 1
// 10 2
// 7 3
// 9 4
// 10 7
// 2 6
// 7 9

// Output 
// 4

// Explanation: the shortest itinerary is: 1, 4, 5, 6, 8 and the length is 4  

#include <bits/stdc++.h>

using namespace std;

const int MAX = 10010;
const int INF = 1e9;

int n, D;
int x[MAX], y[MAX];
vector<vector<int> > Graph;
int trace[MAX];

void inputData(){
    cin >> n >> D;
    Graph.resize(n+1);
    for (int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }
}

int dis(int u, int v){
    return (int) sqrt((x[u] - x[v])*(x[u] - x[v]) + (y[u] - y[v])*(y[u] - y[v]));
}

void buildGraph(){
    for (int i = 1; i <= n; i++){
        for (int j = i+1; j <= n; j++){
            if (dis(i, j) <= D){
                Graph[i].push_back(j);
                Graph[j].push_back(i);
            }
        }
    }
}

int BFS(){
    queue<int> q;
    q.push(1);
    memset(trace, 0, sizeof trace);
    trace[1] = -1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : Graph[u]){
            if (trace[v] == 0){
                trace[v] = u;
                if (v == n) return 1;
                q.push(v);
            }
        }
    }
    return 0;
}

int main(int argc, const char** argv) {
    inputData();
    buildGraph();

    if (BFS()){
        int res = 0;
        int u = n;
        while (trace[u] != -1){
            res += 1;
            u = trace[u];
        }
        cout << res;
    } else cout << -1;

    return 0;
}