// Problem: LAB.05.03 - Bus inter-city
// Description
// Có n thành phố 1, 2, ..., n. Giữa 2 thành phố i và j có thể có 1 con đường (2 chiều) kết nối giữa chúng. 
// Mỗi thành phố i có tuyến buýt i với C[i] là giá vé mỗi khi lên xe và D[i] là số thành phố tối đa mà buýt i có thể đi đến trên 1 hành trình đi qua các con đường kết nối.
// Hãy tìm cách đi từ thành phố 1 đến thành phố n với số tiền phải trả là ít nhất
// Input
// Dòng 1: chứa 2 số nguyên dương n và m trong đó n là số thành phố và m là số con đường kết nối các thành phố (1 <= n <= 5000, 1 <= m <= 10000)
// Dòng i+1 (i = 1,2,...,n): chứa 2 số nguyên dương C[i] và D[i] (1 <= C[i] <= 10000, 1 <= D[i] <= 100)
// Dòng n+1+i (i = 1, 2, ..., m): chứa 2 số nguyên dương i và j trong đó giữa thành phố i và j có con đường kết nối
// Output
// Số tiền tối thiểu phải bỏ ra để đi buýt từ thành phố 1 đến thành phố n

// Example
// Input
// 6 6
// 10 2
// 30 1
// 50 1
// 20 3
// 30 1
// 20 1
// 1 2
// 1 3
// 1 5
// 2 4
// 2 5
// 4 6
// Output
// 30

// Giải thích: 
// -Lên buýt 1 từ thành phố 1 đến thành phố 4 mất 10 đồng
// -Lên buýt 4 từ thành phố 4 đến thành phố 6 mất 20 đồng
// Tổng cộng mất 10 + 20 = 30 đồng

#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

vector<vector<int>> Graph;
vector<pair<int, int>> bus;
vector<int> min_cost;

vector<int> BFS(int start, int maxDis) {
    vector<int> vt;
    queue<pair<int, int>> q; // (u city, u d)
    unordered_set<int> visited;

    q.push({start, 0});

    while (!q.empty()) {
        auto u = q.front().first;
        auto d = q.front().second;
        q.pop();

        if (visited.count(u) || d > maxDis) continue;
        visited.insert(u);

        vt.push_back(u);

        for (int v : Graph[u]) {
            if (!visited.count(v)) q.push({v, d + 1});
        }
    }

    return vt;
}

int Dijkstra(int n, int m) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    min_cost.assign(n + 1, INF);

    pq.push({0, 1});
    min_cost[1] = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        if (u == n) return cost;

        if (cost > min_cost[u]) continue;

        auto vt = BFS(u, bus[u - 1].second);

        for (int v : vt) {
            int new_cost = cost + bus[u - 1].first;
            if (new_cost < min_cost[v]) {
                min_cost[v] = new_cost;
                pq.push({new_cost, v});
            }
        }
    }

    return -1; 
}

int main(int argc, char const *argv[]){
    int n, m;
    cin >> n >> m;

    bus.resize(n); 
    for (int i = 0; i < n; ++i) {
        cin >> bus[i].first >> bus[i].second;
    }

    Graph.resize(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    int res = Dijkstra(n, m);
    cout << res;

    return 0;
}
