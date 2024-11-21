// Problem: LAB.04.02 - Nurse
// Description
// The director of a hospital want to schedule a working plan for a nurse in a given period of N consecutive days 1,..., N. Due to the policy of the hospital, each nurse cannot work all the days 1,..., N. Instead, there must be days off in which the nurse need to take a rest. A working plan is a sequence of disjoint working periods. A working period of a nurse is defined to be a sequence of consecutive days on which the nurse must work and the length of the working period is the number of consecutive days of that working period. The hospital imposes two constraints:
// Each nurse can take a rest only one day between two consecutive working periods. it means that if the nurse takes a rest today, then she has to work tomorrow (1)
// The length of each working period must be greater or equal to K1 and less than or equal to K2 (2) 
// The director of the hospital want to know how many possible working plans satisfying above constraint?	
// Input
//  The input consists of one line which contains 3 positive integers N, K1, K2 (2 <= N <=  1000, K1 < K2 <= 400)
// Output
// The output consists of only one single integer M modulo 10^9+7 where M is the total working plans satisfying the above constraints.

// Example
// Input
// 6 2 3
// Output
// 4

#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9 + 7;

int main(int argc, char const *argv[]){
    int N, K1, K2;
    cin >> N >> K1 >> K2;

    vector<int> dp_work(N + 1, 0);
    vector<int> dp_rest(N + 1, 0);
    dp_work[0] = 1;
    dp_rest[0] = 1;

    for (int i = 1; i <= N; i++){
        dp_work[i] = dp_rest[i-1];
        int work = 0;
        for( int j = i - K2; j <= i - K1; j++){
            if (j >= 0) work = (work + dp_work[j]) % MOD;
        }
        dp_rest[i] = work;
    }

    cout << (dp_work[N] + dp_rest[N]) % MOD;
    return 0;
}
