// Problem: Simmulation Priority Queue
// Description
// A Database D stores elements which are positive integers. Perform a sequence of operations over D including:
// PUSH e: add the element e to D (e is a positive integer)
// POP: remove the element having smallest value out of D and return this element

// Input
// Each line contain the information about one operation (the format is described above)
// The input is terminated by a line containing the character #

// Output
// Write the result of the POP operation on separate lines

// Example
// Input
// PUSH 10
// PUSH 4
// PUSH 1 
// PUSH 8
// PUSH 7
// POP
// PUSH 2
// PUSH 9
// POP
// POP
// POP
// #

// Output
// 1
// 2
// 4
// 7

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    priority_queue<int, vector<int>, greater<int>> pq;
    string s;
    while (cin >> s){
        if (s == "PUSH"){
            int v;
            cin >> v;
            pq.push(v);
        } else if (s == "POP"){
            if (pq.empty()) cout << "NULL" << endl;
            else {
                cout << pq.top() << endl;
                pq.pop();
            } 
        } else break;
    }

    return 0;
}