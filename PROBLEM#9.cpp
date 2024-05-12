#include <iostream>
#include <vector>
#include <string>

using namespace std;

/* PROBLEM 9: BACKTRACKING*/

class Solution {
public:
    bool dfs(int row, int col, int ind, vector<vector<char>>& board, string& word,
        vector<vector<int>>& vis) {
        if (static_cast<int>(word.size()) == ind) { // Cast to int for comparison
            return true;
        }
        int n = board.size(), m = board[0].size();
        vis[row][col] = 1;

        int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
        int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

        for (int i = 0; i < 8; i++) {
            int nrow = row + dx[i];
            int ncol = col + dy[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] &&
                board[nrow][ncol] == word[ind]) {
                if (dfs(nrow, ncol, ind + 1, board, word, vis) == true)
                    return true;
            }
        }

        vis[row][col] = 0;
        return false;
    }

    vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dict) {
        vector<string> ans;
        int n = board.size(), m = board[0].size();

        for (size_t d = 0; d < dict.size(); d++) {
            bool flag = true;
            vector<vector<int>> vis(n, vector<int>(m, 0));
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (board[i][j] == dict[d][0] && !vis[i][j] &&
                        dfs(i, j, 1, board, dict[d], vis) == true) {
                        ans.push_back(dict[d]);
                        flag = false;
                        break;
                    }
                }
                if (flag == false)
                    break;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<char>> board = {
        {'C', 'A', 'P'},
        {'A', 'N', 'D'},
        {'T', 'I', 'E'}
    };
    vector<string> dictionary = { "CAT" };
    vector<string> result = sol.wordBoggle(board, dictionary);
    for (const string& word : result) {
        cout << word << endl;
    }

    return 0;
}