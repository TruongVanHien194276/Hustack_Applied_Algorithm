// Problem: Chapter 3 - CBUS
// Description
// There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n). There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most k passengers on the bus). You are given the Cance matrix c in which c(i,j) is the traveling distance from point i to point j (i, j = 0,1,…, 2n). Compute the shortest route for the bus, serving n passengers and coming back to point 0.
// Input
// Line 1 contains n and k (1≤n≤11,1≤k≤10)
//  Line i+1 (i=1,2,…,2n+1) contains the (i−1)th
//  line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).
// Output
// Unique line contains the length of the shortest route.
// Example
// Input
// 3  2
// 0  8  5  1  10  5  9
// 9  0  5  6  6  2  8
// 2  2  0  3  8  7  2
// 5  3  4  0  3  2  7
// 9  6  8  7  0  9  10
// 3  8  10  6  5  0  2
// 3  4  4  5  2  2  0
// Output
// 25

// #include <bits/stdc++.h>

// using namespace std;

// const int INF = 1e9;

// int n, k;
// vector<vector<int>> C;
// vector<vector<vector<int>>> dp;

// int CBUS(int pos, int onBoard, int picked, vector<int>& pg) {
//     if (picked == (1 << (2 * n)) - 1) return C[pos][0];

//     if (dp[pos][onBoard][picked] != -1) return dp[pos][onBoard][picked];

//     int res = INF;
//     for (int i = 1; i <= n; i++) {
//         if (!(picked & (1 << (i - 1))) && pg.size() < k) {
//             int new_mask = picked | (1 << (i - 1));
//             pg.push_back(i);
//             res = min(res, C[pos][i] + CBUS(i, onBoard + 1, new_mask, pg));
//             pg.pop_back();
//         }
//     }

//     for (int i = 0; i < pg.size(); i++) {
//         int p = pg[i];
//         int dropPoint = p + n;
//         if (!(picked & (1 << (p + n - 1)))) {
//             pg.erase(pg.begin() + i);
//             int new_mask = picked | (1 << (dropPoint - 1));
//             res = min(res, C[pos][dropPoint] + CBUS(dropPoint, onBoard - 1, new_mask, pg));
//             pg.insert(pg.begin() + i, p);
//         }
//     }

//     dp[pos][onBoard][picked] = res;
//     return res;
// }

// int main(int argc, char const *argv[]){
//     cin >> n >> k;

//     C.resize(2 * n + 1, vector<int>(2 * n + 1));
//     for (int i = 0; i <= 2 * n; i++) {
//         for (int j = 0; j <= 2 * n; j++) {
//             cin >> C[i][j];
//         }
//     }

//     dp.resize(2 * n + 1, vector<vector<int>>(n + 1, vector<int>((1 << (2 * n)), -1)));

//     vector<int> pg;
//     int res = CBUS(0, 0, 0, pg);
//     cout << res;

//     return 0;
// }

// using branch and bound

#include <bits/stdc++.h>

using namespace std;

const int N = 12;
const int INF = 1e9;

int n, k;
int c[2*N+1][2*N+1];
int c_min = INF;
bool visited[2*N+1];
int load; 
int x[2*N+1];
int f, res = INF;

void inputData(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i = 0; i <= 2 * n; i++){
        for (int j = 0; j <= 2 * n; j++){
            cin >> c[i][j];
            if (c[i][j]) c_min = min(c_min, c[i][j]);
        }
    }
    visited[0] = true;
    x[0] = 0;
}

bool check(int v){
    if (visited[v]) return false;
    if (v <= n && load == k) return false;
    if (v > n && !visited[v - n]) return false;

    return true;
}

void solution(){
    res = min(res, f + c[x[2 * n]][0]);
}
void TRY(int u){
    for (int v = 1; v <= 2*n; v++){
        if (check(v)){
            x[u] = v;
            visited[v] = true;
            if (v > n) --load;
            else ++load;
            f += c[x[u - 1]][v];

            if (u == 2 * n) solution();
            else if (f + (2 * n - u + 1) * c_min < res) TRY(u + 1);

            visited[v] = false;
            if (v > n) ++load;
            else --load;
            f -= c[x[u - 1]][v];
        }
    }
}

int main(int argc, char const *argv[]){
    inputData();
    TRY(1);
    cout << res << endl;
}