// Problem: Analyze orders raised over times
// Description
// Given a dataset about orders raised over the time, each item is under the format: <OrderID> <TimePoint>
// in which the order <OrderID> (<OrderID> is a string of length from 2 to 15) is raised at time point <TimePoint> (the <TimePoint> is a string of length 8 representing the time point hh:mm:ss, for example, 08:30:14 means 8 hour 30 minutes 14 seconds)
// Perform a sequence of queries about the given dataset of 3 categories:
// ?number_orders: return the number of orders raised 
// ?number_orders_in_period <FromTimePoint> <ToTimePoint>: return the number of orders raised in the period from time point <FromTimePoint> to time point <ToTimePoint>
// ?number_orders_at_time <TimePoint>: return the number of orders raised at the time point <TimePoint>

// Input
// The first block is a sequence of lines (number of lines can be up to 100000), each line contains an information about an order raised with the format above. The first block is terminated with a line containsing the character #
// The second line is a sequence of lines (number of lines can be up to 100000), each line contains a query described above. The second line is terminated with a line containing ###

// Output
// Write in each line, the result of the correspinding query.

// Example
// Input
// ORD0001 18:48:34
// ORD0002 15:53:51
// ORD0003 08:07:12
// ORD0004 04:06:44
// ORD0005 05:11:40
// ORD0006 00:18:17
// ORD0007 05:09:07
// ORD0008 18:48:34
// ORD0009 02:31:11
// ORD0010 18:48:34
// #
// ?number_orders
// ?number_orders_in_period 03:00:00 06:30:45
// ?number_orders_at_time 18:48:34
// ###

// Output 
// 10
// 3
// 3

#include <bits/stdc++.h>

using namespace std;

int n = 0; // number_orders
int cnt1[86405]; // number_orders_in_period
map<int,int> cnt2; // number_orders_at_time

int convertTime(string s){
    return stoi(s.substr(0,2))*3600 + stoi(s.substr(3,2))*60 + stoi(s.substr(6,2));
}

int main(int argc, char const *argv[]){
    memset(cnt1, 0, sizeof(cnt1));
    string s;
    while (getline(cin, s) && s != "#") {
        string orderID, time;
        stringstream ss(s);
        ss >> orderID >> time;
        n += 1;

        int tmp = convertTime(time);
        cnt1[tmp]++;
        cnt2[tmp]++;
    }

    for (int i = 1; i<86400; i++){ 
        cnt1[i] += cnt1[i-1];
    }

    while (getline(cin, s) && s != "###") {
        stringstream ss(s);
        string cmd, time1, time2;
        ss >> cmd >> time1 >> time2;

        if (cmd == "?number_orders") cout << n << endl;
        else if (cmd == "?number_orders_in_period") cout << cnt1[convertTime(time2)] - cnt1[convertTime(time1)-1] << endl;
        else if (cmd == "?number_orders_at_time") cout << cnt2[convertTime(time1)] << endl;
    }

    return 0;
}
