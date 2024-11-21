// Problem: LAB.04.03 - Warehouse
// Description
// A truck is planned to arrive at some stations among N stations 1, 2, . . ., N located on a line. Station i (i = 1,…,N) has coordinate i and has following information
// ai : amount of goods
// ti : pickup time duration for taking goods
// The route of the truck is a sequence of stations x1 < x2 < . . . < xk (1 ≤ xj ≤ N, j = 1,…, k). Due to technical constraints, the distance between two consecutive stations that the truck arrives xi and xi+1 is less than or equal to D and the total pickup time duration cannot exceed T. Find a route for the truck such that total amount of goods picked up is maximal.
// Input
// Line 1: N, T, D (1 <= N <= 1000, 1 <= T <= 100, 1 <= D <= 10)
// Line 2: a1,. . ., aN (1 <= ai <= 10)
// Line 3: t1, . . ., tN (1 <=  ti <= 10)
// Output
// Write the total amount of goods that the truck picks up in the route.
// Example
// Input
// 6 6 2
// 6 8 5 10 11 6
// 1 2 2 3 3 2

// Output
// 24

#include <bits/stdc++.h>

using namespace std;

const int MAX = 1010;

int N, T, D;
int a[MAX], t[MAX];
int dp[MAX][MAX] = {0};

void inputData(){
	cin >> N >> T >> D;
	for (int i = 1; i <= N; i++){
		cin >> a[i];
	}
	for (int i = 1; i <= N; i++){
		cin >> t[i];
	}
}

void TRY(){
	for (int i = 1; i <= N; i++){
		for (int k = 1; k <= T; k++){
			dp[i][k] = a[i];
			if (k < t[i]){
				dp[i][k] = 0;
				continue;
			}
			if (i >= D){
				int tmp = 0;
				for (int j = i-D; j < i; j++){
					tmp = max(dp[j][k-t[i]] + a[i], tmp);
					dp[i][k] = tmp;
				}
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= N; i++){
		for (int j = 1; j <= T; j++){
			res = max(res, dp[i][j]);
		}
	}
	cout << res;
}

int main(int argc, const char** argv) {
    inputData();
    TRY();
	return 0;
}