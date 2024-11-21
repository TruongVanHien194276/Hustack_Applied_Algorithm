// Problem: Chapter 5 - Max Flow
// Description
// Given a network G = (V, E) which is a directed weighted graph. Node s is the source and node t is the target. c(u,v) is the capacity of the arc (u,v). Find the maximum flow on G.
// Input
// •Line 1: two positive integers N and M (1 <= N <= 10^4, 1 <= M <= 10^6)
// •Line 2: contains 2 positive integers s and t
// •Line i+2 (I = 1,. . ., M): contains two positive integers u and v which are endpoints of ith arc
// Output:  Write the value of the max-flow found
// Example
// Input
// 7 12
// 6 7
// 1 7 7
// 2 3 6
// 2 5 6
// 3 1 6
// 3 7 11
// 4 1 7
// 4 2 4
// 4 5 5
// 5 1 4
// 5 3 4
// 6 2 8
// 6 4 10
// Output
// 17

#include <bits/stdc++.h> 

using namespace std;

const int MAX = 10010;
const int INF = 1e9;

int n, m, s, t;
vector<vector<int> > Graph;
int c[MAX][MAX], f[MAX][MAX];
int trace[MAX];

void inputData(){
    cin >> n >> m;
    cin >> s >> t;
    Graph.resize(n+1);
    for (int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
        c[u][v] = w;
    }
}


int BFS(){
    queue<int> q;
    q.push(s);
    memset(trace, 0, sizeof trace);
    trace[s] = -1;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        for (int v : Graph[u]){
            if (trace[v] == 0 && f[u][v] < c[u][v]){
                trace[v] = u;
                if (v == t) return 1;
                q.push(v);
            }
        }
    }
    return 0;
}

int maxFlow(){
    int res = 0;
    while (BFS()){
        int minFlow = INF;
        for (int v = t; v != s; v = trace[v]){
            minFlow = min(minFlow, c[trace[v]][v] - f[trace[v]][v]);
        }
        for (int v = t; v != s; v = trace[v]){
            f[trace[v]][v] += minFlow;
            f[v][trace[v]] -= minFlow;
        }
        res += minFlow;
    }
    return res;
}

int main(int argc, const char** argv) {
    inputData();
    cout << maxFlow();
    return 0;
}