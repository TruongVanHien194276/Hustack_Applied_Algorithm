#include <bits/stdc++.h>

using namespace std;

const int MAX = 1000010;

int n, M, a[MAX];

void inputData(){
    cin >> n >> M;
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
}

int main(int argc, char const *argv[]){
    inputData();

    vector<int> f(M + 1, 0);
    f[0] = 1;

    for (int i = 0; i < n; i++){
        for (int j = a[i]; j <= M; j++){
            f[j] += f[j - a[i]];
        }
    }

    cout << f[M] << endl;
    return 0;
}