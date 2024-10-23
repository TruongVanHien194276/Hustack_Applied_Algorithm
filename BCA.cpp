// Problem: LAB.02.03 - Balanced Courses Assignments
// Description
// At the beginning of the semester, the head of a computer science department D have to assign courses to is in a balanced way. The department D has m is T={1,2,...,m} and n courses C={1,2,...,n}. Each i t∈T has a preference list which is a list of courses he/she can teach depending on his/her specialization. We known a list of pairs of conflicting two courses that cannot be assigned to the same i as these courses have been already scheduled in the same slot of the timetable. The load of a i is the number of courses assigned to her/him. How to assign nn courses to mm i such that each course assigned to a i is in his/her preference list, no two conflicting courses are assigned to the same i, and the maximal load is minimal.
// Input
// The input consists of following lines
// Line 1: contains two integer m and n (1≤m≤10, 1≤n≤30)
// Line i+1: contains an positive integer k and k positive integers indicating the courses that i i can teach (∀i=1,…,m)
// Line m+2: contains an integer k
// Line i+m+2: contains two integer i and j indicating two conflicting courses (∀i=1,…,k)
// Output
// The output contains a unique number which is the maximal load of the is in the solution found and the value -1 if not solution found.
// Example
// Input
// 4 12
// 5 1 3 5 10 12
// 5 9 3 4 8 12
// 6 1 2 3 4 9 7
// 7 1 2 3 5 6 10 11
// 25
// 1 2
// 1 3
// 1 5
// 2 4
// 2 5
// 2 6
// 3 5
// 3 7
// 3 10
// 4 6
// 4 9
// 5 6
// 5 7
// 5 8
// 6 8
// 6 9
// 7 8
// 7 10
// 7 11
// 8 9
// 8 11
// 8 12
// 9 12
// 10 11
// 11 12

// Output
// 3

#include<bits/stdc++.h>

using namespace std;

const int INF = 1e9;
const int MAX = 35;

int m, n; 
int course[MAX];
int TeacherChoice[MAX];
vector<vector<int> > list_course; 
vector<vector<int> > list_conflict; 
int load_teacher[MAX];
int load_max_teacher = 0;
int minAll = 1e9;

void inputData(){
    cin >> m >> n;
    list_course.resize(m+1);

    int k; 
    for (int i = 0; i < m; i++){
        cin >> k; 
        for (int j = 0; j < k; j++){
            int temp; 
            cin >> temp;
            list_course[i].push_back(temp);
        }
    }

    int K; 
    cin >> K;
    list_conflict.resize(n+1);
    for (int i = 0; i < K; i++){
        int t1, t2;
        cin >> t1 >> t2;
        list_conflict[t1].push_back(t2); 
        list_conflict[t2].push_back(t1); 
    }
}

bool check(int a, int i){
    int tick = 0;
    for (int j = 0; j < list_course[i].size(); j++){
        if (list_course[i].at(j) == a) tick++;
    }
    if (tick == 0) return false;

    for (int j = 0; j < list_conflict[a].size(); j++){
        if (course[list_conflict[a].at(j)] == i && list_conflict[a].at(j) < a) return false;
    }

    return true;
}

void solution(){
    minAll = min(minAll, load_max_teacher);
}

void TRY(int a){
    for (int i = 0; i < m; i++){
        if (check(a, i)){
            course[a] = i;
            load_teacher[i]++;
            int pre = load_max_teacher;
            load_max_teacher = max(load_max_teacher, load_teacher[i]);
            
            if (a == n) solution();
            else{
                if (load_max_teacher < minAll) TRY(a+1);
            }

            load_teacher[i]--;
            load_max_teacher = pre;
        }
    }
}

int main(int argc, const char** argv) {
    inputData();
    TRY(1);
    cout << minAll;
    return 0;
}
