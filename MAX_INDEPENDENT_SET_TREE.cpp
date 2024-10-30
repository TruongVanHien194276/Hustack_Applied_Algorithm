// Problem: Max Independent Set on a Tree
// Description
// Cho cây T = (V,E) trong đó V = {1,…,n} là tập các đỉnh và E là tập gồm n-1 cạnh. Mỗi đỉnh v của đồ thị có trọng số w(v). Hãy chọn ra tập S các đỉnh sao cho hai đỉnh kề nhau không cùng được chọn và tổng trọng số các đỉnh được chọn là lớn nhất.
// Dữ liệu
// · Dòng 1: ghi số nguyên dương n (1 <= n <= 100000)
// · Dòng 2: ghi n số nguyên dương w(1), w(2), …, w(n) là trọng số các đỉnh tương ứng
// · Dòng i+2 (i = 1,…,n-1): ghi 2 số nguyên dương u và v là 2 đầu mút của cạnh thứ i của T
// Kết quả:
// · Ghi ra tổng trọng số của các đỉnh được chọn
// Ví dụ
// Dữ liệu
// 9
// 9 5 10 4 3 2 6 1 8
// 1 5
// 2 3
// 2 4
// 2 6
// 3 5
// 6 7
// 6 8
// 6 9
// Kết quả
// 38

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100010;

int n, w[MAX];
int u, v;
vector<int> adj[MAX];
long long dp[MAX][2];
long long res = 0;

void DFS(int u, int p){
    dp[u][0] = 0;
    dp[u][1] = w[u];
    for (int v : adj[u]){
        if (v == p) continue;
        DFS(v, u);
        dp[u][0] += max(dp[v][0], dp[v][1]);
        dp[u][1] += dp[v][0];
    }
    res = max(res, max(dp[u][0], dp[u][1]));
}

int main(int argc, const char** argv) {
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> w[i];
    }

    for (int i = 1; i < n; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1, 0);
    cout << res;

    return 0;
}