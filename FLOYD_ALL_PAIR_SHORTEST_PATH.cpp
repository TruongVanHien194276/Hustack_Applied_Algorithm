// Problem: All pair shortest Path
// Description
// Given a directed graph G = (V,E), in which V = {1, 2, ..., n} is the set of nodes. Find the shortest path between all pair of 2 nodes of G: d[u,v] is the length of the shortest path from u to v in G.
// Input
// Line 1: contains 2 positive integers n and m (1 <= n <= 1000, 1 <= m <= 1000000)
// Line i+1 (i = 1, 2, ..., m): contains 3 integers u, v, w in which w is the weight of arc(u,v)
// Output
// Line i (i = 1, 2, ..., n): wirte the ith row of the distance matrix d

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9; 
const int MAX = 1010;

vector<pair<int, int> > Graph[MAX]; 
vector<vector<int>n> d;              
int n, m;

void Dijkstra(int a) {
    vector<int> d(n+1, INF); 
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[a] = 0; 
    pq.push({0, a}); 

    while (!pq.empty()) {
        auto [curDist, u] = pq.top();
        pq.pop();

        if (curDist > d[u]) continue; 

        for (auto [v, weight] : Graph[u]) {
            if (d[u] + weight < d[v]) {
                d[v] = d[u] + weight;
                pq.push({d[v], v});
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        d[a][i] = d[i];
    }
}

int main(int argc, char const *argv[]){
    cin >> n >> m;
    d.assign(n+1, vector<int>(n+1, INF));

    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Graph[u].push_back({v, w});
    }

    for (int i = 1; i <= n; i++) {
        Dijkstra(i);
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
