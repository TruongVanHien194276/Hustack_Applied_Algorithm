// Problem: Chapter 4 - TSP - Large Scale
// Description
// There are n cities 1, 2, ..., n. The travel dis from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  A person wants to find a closed tour that visits each city exactly once (excelt the starting city). Find the itinerary for that person so that the total travel dis is minimal.
// A solution is represented by a sequence x1, x2, . . ., xn  (a permutation of 1, 2, . . ., n) in which the closed tour is: x1  ->  x2 ->  x3 ->  . . . ->  xn ->  x1.
// Input
// Line 1: a positive integer n (1 <= n <= 1000)
// Line i+1 (i = 1, . . ., n): contains the ith row of the dis matrix x (elements are separated by a SPACE character)
// Output
// Line 1: write n 
// Line 2: write the sequence of points x1, x2, . . ., xn (a permutation of 1, 2, . . ., n) of the itinerary found.
// Example
// Input
// 4
// 0 1 1 9
// 1 0 9 3
// 1 9 0 2
// 9 3 2 0
// Output
// 4
// 1 3 2 4

// solution 1
#include <bits/stdc++.h>

using namespace std;

const int MAX = 2000;

int n;
int c[MAX][MAX];
bool visited[MAX];
int path[MAX];

int cal_dis(int route[], int n){
    int dis = 0;
    for(int i = 2; i <= n; i++){
        dis = dis + c[route[i-1]][route[i]];
    }
    dis = dis + c[route[n]][route[1]];
    return dis; 
}

void opt_func(int a[], int n, int i, int j, int new_route[]){
    for (int index = 1; index <= i; index++){
        new_route[index] = a[index];
    }
    for (int index = i + 1; index <= j; index++){
        new_route[i + 1 + j - index] = a[index];
    }
    for (int index = j + 1; index <= n; index++){
        new_route[index] = a[index];
    }
}

int main(int argc, char const *argv[]){
    cin >> n;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> c[i][j];
        }
    }

    memset(visited, false, MAX);

    int opt = 0;
    path[1] = 1;
    visited[1] = true;

    for (int i = 2; i <= n; i++){
        int min = INT_MAX;
        int min_index;
        for (int j = 1; j <= n; j++){
            if (!visited[j] && c[path[i-1]][j] < min ){
                min = c[path[i-1]][j];
                min_index = j;
            }
        }
        path[i] = min_index;
        visited[min_index] = true;
        opt = opt + c[path[i-1]][min_index];
    }

    opt = opt + c[path[n]][1];

    int new_route[n+1];
    int dis_cur = 0;
    bool is_improve = true;
    int best_i, best_j;
    int temp;
    while (is_improve){
        is_improve = false;
        for (int i = 1; i <= n-2; i++){
            for (int j = i + 2; j <= n; j++){
                opt_func(path , n, i, j, new_route);
                dis_cur = cal_dis(new_route, n);
                if (dis_cur < opt){
                    is_improve = true;
                    opt = dis_cur;
                    best_i = i;
                    best_j = j;
                }
            }    
        }
        
        if (is_improve){
            while (best_i + 1 < best_j){
                temp = path[best_i + 1];
                path[best_i + 1] = path[best_j];
                path[best_j] = temp;
                best_i++;
                best_j--;
            }
        }
        
    }

    cout << n << endl;
    for (int i = 1; i <= n; i++){
        cout << path[i] << " ";
    }

    return 0;
}

// solution 2

// #include <bits/stdc++.h>

// using namespace std;

// const int MAX = 1010;
// int n;
// int c[MAX][MAX];
// vector<int> path;

// int cal_dis(vector<int> route) {
//     int dis = 0;
//     for (size_t i = 0; i < route.size(); i++) {
//         dis += c[route[i]][route[(i + 1) % n]];
//     }
//     return dis;
// }

// void nearest_neighbor() {
//     vector<bool> visited(n, false);
//     path.push_back(0); 
//     visited[0] = true;

//     for (int i = 1; i < n; i++) {
//         int last = path.back();
//         int next_city = -1;
//         int min_dist = INT_MAX;

//         for (int j = 0; j < n; j++) {
//             if (!visited[j] && c[last][j] < min_dist) {
//                 min_dist = c[last][j];
//                 next_city = j;
//             }
//         }
//         path.push_back(next_city);
//         visited[next_city] = true;
//     }
// }

// void two_opt() {
//     bool improve = true;
//     while (improve) {
//         improve = false;
//         for (int i = 1; i < n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 reverse(path.begin() + i, path.begin() + j + 1);
//                 int new_dist = cal_dis(path);

//                 if (new_dist < cal_dis(path)) improve = true;
//                 else reverse(path.begin() + i, path.begin() + j + 1); 
//             }
//         }
//     }
// }

// int main(int argc, char const *argv[]){
//     cin >> n;
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cin >> c[i][j];
//         }
//     }

//     nearest_neighbor(); 
//     two_opt(); 

//     cout << n << endl;
//     for (int i = 0; i < n; i++) {
//         cout << path[i] + 1 << " "; 
//     }
//     cout << endl;

//     return 0;
// }
