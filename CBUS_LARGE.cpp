// Problem: CBUS Large-Size
// Description
// There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point i + n (i = 1,2,…,n). There is a bus located at point 0 and has k places for transporting the passengers (it means at any time, there are at most k passengers on the bus). You are given the distance matrix c in which c(i,j) is the traveling distance from point i to point j (i, j = 0,1,…, 2n). Compute the shortest route for the bus, serving n passengers and coming back to point 0.
// Input
// Line 1 contains n and k (1≤n≤1000,1≤k≤50)
// Line i+1 (i=1,2,…,2n+1) contains the (i−1)th line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).
// Output
// Line 1: write the value n
// Line 2: Write the sequence of points (pickup and drop-off) of passengers (separated by a SPACE character)
// Example
// Input
// 5 3
// 0 5 8 11 12 8 3 3 7 5 5 
// 5 0 3 5 7 5 3 4 2 2 2 
// 8 3 0 7 8 8 5 7 1 6 5 
// 11 5 7 0 1 5 9 8 6 5 6 
// 12 7 8 1 0 6 10 10 7 7 7 
// 8 5 8 5 6 0 8 5 7 3 4 
// 3 3 5 9 10 8 0 3 4 5 4 
// 3 4 7 8 10 5 3 0 6 2 2 
// 7 2 1 6 7 7 4 6 0 5 4 
// 5 2 6 5 7 3 5 2 5 0 1 
// 5 2 5 6 7 4 4 2 4 1 0 

// Output
// 5 
// 1 2 6 7 5 10 3 4 8 9

