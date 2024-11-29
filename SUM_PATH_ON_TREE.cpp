// Problem: Chapter 5 - Sum of length of paths from root on a tree
// Description
// Given a tree T=(V,E) in which V={1,. . ., n} is the set of nodes. Each edge (u,v) of T has length w(u,v). Denote f(v) the sum of length of paths from all other nodes to v. Write a program to compute max{f(1), .  . ., f(n)}.

// Input
// Line 1 contains a positive integer n (2 <= n <= 10^5)
// Line i+1 (i=1, . . ., n): contains u, v and w in which w is the weight of the edge (u,v)
// Output
// Write the value max{f(1), . . , f(n}.

// Example
// Input
// 4
// 1 2 1
// 1 3 3
// 3 4 2
// Output
// 13

#include <bits/stdc++.h>

using namespace std;

const int MAX = 100010;

vector<pair<int, int> > Tree[MAX]; 
int len[MAX];      
int f[MAX];              
int n;

void DFS1(int u, int parent) {
    len[u] = 1; 
    for (auto& v : Tree[u]) {
        int nb = v.first;
        int w = v.second;
        if (nb != parent) {
            DFS1(nb, u);
            len[u] += len[nb];
            f[1] += len[nb] * w; 
        }
    }
}

void DFS2(int u, int parent) {
    for (auto& v : Tree[u]) {
        int nb = v.first;
        int w = v.second;
        if (nb != parent) {
            f[nb] = f[u] + (n - len[nb]) * w - (len[nb] * w);
            DFS2(nb, u);
        }
    }
}

int main(int argc, char const *argv[]){
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Tree[u].push_back(make_pair(v, w)); 
        Tree[v].push_back(make_pair(u, w));
    }

    DFS1(1, -1);
    DFS2(1, -1);

    int res = 0;
    for (int i = 1; i <= n; i++) {
        res = max(res, f[i]);
    }
    cout << res;

    return 0;
}
