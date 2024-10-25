// Problem: Chapter 4 - TSP - Large Scale
// Description
// There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  A person wants to find a closed tour that visits each city exactly once (excelt the starting city). Find the itinerary for that person so that the total travel distance is minimal.
// A solution is represented by a sequence x1, x2, . . ., xn  (a permutation of 1, 2, . . ., n) in which the closed tour is: x1  ->  x2 ->  x3 ->  . . . ->  xn ->  x1.
// Input
// Line 1: a positive integer n (1 <= n <= 1000)
// Line i+1 (i = 1, . . ., n): contains the ith row of the distance matrix x (elements are separated by a SPACE character)
// Output
// Line 1: write n 
// Line 2: write the sequence of points x1, x2, . . ., xn (a permutation of 1, 2, . . ., n) of the itinerary found.
// Example
// Input
// 4
// 0 1 1 9
// 1 0 9 3
// 1 9 0 2
// 9 3 2 0
// Output
// 4
// 1 3 2 4

