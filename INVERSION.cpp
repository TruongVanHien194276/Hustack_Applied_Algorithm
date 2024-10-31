// Problem: LAB.03.02 - Inversion
// Description
// Given a sequence of integers a1, a2, ..., an. A pair (i, j) is call an inversion if i < j and ai > aj. Compute the number Q of inversions
// Input
// Line 1: contains a positive integer n (1 <= n <= 10^6)
// Line 2: contains a1, a2, ..., an (0 <= ai <= 10^6)
// Output
// Write the value Q modulo 10^9 +7

// Example
// Input
// 6
// 3 2 4 5 6 1
// Output
// 6

#include <bits/stdc++.h>

using namespace std; 

const int MOD = 1e9 + 7;

vector<int> temp; 
long long cnt = 0;

void mergeAndCount(vector<int>& arr, int left, int mid, int right) {
    int i = left;    
    int j = mid + 1;   
    int k = left;      

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            temp[k++] = arr[j++];
            cnt = (cnt + (mid - i + 1)) % MOD; 
        }
    }

    while (i <= mid) {
        temp[k++] = arr[i++];
    }

    while (j <= right) {
        temp[k++] = arr[j++];
    }

    for (int idx = left; idx <= right; idx++) {
        arr[idx] = temp[idx];
    }
}

void mergeSortAndCount(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSortAndCount(arr, left, mid);     
        mergeSortAndCount(arr, mid + 1, right);  
        mergeAndCount(arr, left, mid, right);    
    }
}

int main(int argc, char const *argv[]){
    int n;
    cin >> n;
    vector<int> a(n);
    temp.resize(n); 

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    mergeSortAndCount(a, 0, n - 1);
    cout << cnt;

    return 0;
}
