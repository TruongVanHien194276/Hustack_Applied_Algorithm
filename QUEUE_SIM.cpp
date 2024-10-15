// Problem: Simulation Queue
// Description
// Perform a sequence of operations over a queue, each element is an integer:
// PUSH v: push a value v into the queue
// POP: remove an element out of the queue and print this element to stdout (print NULL if the queue is empty)
// Input
// Each line contains a command (operration) of type
// PUSH  v
// POP
// Output
// Write the results of POP operations (each result is written in a line)
// Example
// Input
// PUSH 1
// PUSH 2
// PUSH 3
// POP
// POP
// PUSH 4
// PUSH 5
// POP
// #
// Output
// 1
// 2
// 3

// Input
// PUSH 1
// POP
// POP
// PUSH 4
// POP
// #
// Output
// 1
// NULL
// 4

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
    queue<int> q;
    string s;
    while (cin >> s){
        if (s == "PUSH"){
            int v;
            cin >> v;
            q.push(v);
        } else if (s == "POP"){
            if (q.empty()) cout << "NULL" << endl;
            else {
                cout << q.front() << endl;
                q.pop();
            } 
        } else break;
    }

    return 0;
}