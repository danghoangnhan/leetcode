/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(), cols = board[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (dfs(board, visited, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int row, int col, const string& word, int index) {
        if (index == word.size()) return true; // Full word matched
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false; // Out of bounds
        if (visited[row][col] || board[row][col] != word[index]) return false; // Cell mismatch or already visited

        visited[row][col] = true; // Mark as visited

        if (dfs(board, visited, row + 1, col, word, index + 1) ||
            dfs(board, visited, row - 1, col, word, index + 1) ||
            dfs(board, visited, row, col + 1, word, index + 1) ||
            dfs(board, visited, row, col - 1, word, index + 1)) {
            return true;
        }

        visited[row][col] = false; // Unmark, backtrack
        return false;
    }
};
// @lc code=end