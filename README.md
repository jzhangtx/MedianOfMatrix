Median of Row-wise Sorted Matrix


Given an n*m matrix which is sorted row-wise, you need to find the median of the matrix.

Median of a group of numbers is the middle element after they are sorted. Both n and m are guaranteed to be odd numbers, therefore there’s only one middle number.

Example
1 2 3
3 3 4
1 1 2
Median: 2
Testing
Input format
The first line contains an integer ‘T’, denoting the number of test cases.

For each test case the input has the following lines:

The first line contains two space separated integers ‘n’ and ‘m’ denoting the number of rows and columns of the matrix respectively.
The next n lines contain m space-separated integers denoting elements of the matrix.
Note: Each row is sorted.

Output format
For each test case, a line containing the the median element.

Sample Input
3
3 3
1 2 3
3 3 4
1 1 2
3 3
1 2 3
4 5 6
7 8 9
3 5
1 6 7 7 8
2 2 3 3 4
1 2 2 2 2
Expected Output
2
5
2