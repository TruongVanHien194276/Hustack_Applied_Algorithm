
// Problem: Chapter 2 - Segment Tree Simulation - query Max
// Description
// Given a sequence of positive integers a1, a2, . . ., an. Perform a sequence of actions of following types:
// update  i  v : assign ai = v
// get-max  i  j : return the maximum vue of the subsequence ai, ai+1, . . ., aj

// Input
// Line 1: contains a positive integer n (1 <= n <= 100000)
// Line 2: contains a1, a2, . . ., an (1 <= ai <= 10000)
// Line 3: contains a positive integer m (1 <= m <= 100000) which is the number of actions
// Line i + 3 (i = 1, 2, . . ., m): contains an action described above
// Output
// Write in each line the result of the corresponding action of type get-max
// Example
// Input
// 10
// 1 10 9 7 1 4 2 4 8 10 
// 5
// get-max 5 8
// get-max 5 9
// get-max 3 8
// update 9 20
// get-max 4 10

// Ouput
// 4
// 8
// 9
// 20

#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int INF = 1e9;

int n, m;
int a[N], t[N * 4];

void build(int i, int left, int right) {
    if (left == right) {
        t[i] = a[left];
        return;
    }
    int mid = (left + right) / 2;
    build(i * 2, left, mid);
    build(i * 2 + 1, mid + 1, right);
    t[i] = max(t[i * 2], t[i * 2 + 1]);
}

void update(int i, int left, int right, int pos, int v) {
    if (left == right) {
        t[i] = v;
        return;
    }

    int mid = (left + right) / 2;
    if (pos <= mid) update(i * 2, left, mid, pos, v);
    else update(i * 2 + 1, mid + 1, right, pos, v);

    t[i] = max(t[i * 2], t[i * 2 + 1]);
}

int get(int i, int left, int right, int u, int v) {
    if (v < left || right < u) return -INF;
    if (u <= left && right <= v) return t[i];

    int mid = (left + right) / 2;
    return max(get(i * 2, left, mid, u, v), get(i * 2 + 1, mid + 1, right, u, v));
}

int main(int argc, char const *argv[]){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    build(1, 1, n);

    cin >> m;
    while (m--) {
        string cmd;
        cin >> cmd;
        if (cmd == "get-max") {
            int u, v;
            cin >> u >> v;
            cout << get(1, 1, n, u, v) << endl;
        } else {
            int u, v;
            cin >> u >> v;
            update(1, 1, n, u, v);
        }
    }

    return 0;
}

