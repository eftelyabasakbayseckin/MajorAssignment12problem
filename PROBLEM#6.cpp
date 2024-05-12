#include<iostream>
#include<vector>
#include<algorithm>
#define MAX 4
using namespace std;

/*PROBLEM 6: BACKTRACKING */

void getallpath(int matrix[MAX][MAX], int n, int row, int col, vector<string>& ans, string cur)
{
    if (row >= n or col >= n or row < 0 or col < 0 or matrix[row][col] == 0)
        return;

    if (row == n - 1 and col == n - 1)
    {
        ans.push_back(cur);
        return;
    }
    matrix[row][col] = 0;

    getallpath(matrix, n, row - 1, col, ans, cur + "U");
    getallpath(matrix, n, row, col + 1, ans, cur + "R");
    getallpath(matrix, n, row, col - 1, ans, cur + "L");
    getallpath(matrix, n, row + 1, col, ans, cur + "D");

    matrix[row][col] = 1;

    return;
}

vector<string> findPath(int matrix[MAX][MAX], int n) {
    vector<string> ans;
    getallpath(matrix, n, 0, 0, ans, "");
    return ans;
}

int main()
{
    int m[MAX][MAX] = { {1, 0, 0, 0},{1, 1, 0, 1},{1, 1, 0, 0},{0, 1, 1, 1} };
    int n = sizeof(m) / sizeof(m[0]);
    vector<string> ans = findPath(m, n);
    if (ans.empty()) {
        cout << "-1";
    }
    else {
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
    }
    return 0;
}