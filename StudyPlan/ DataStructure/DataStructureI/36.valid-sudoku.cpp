#include <vector>
#include <set>
#include<ctype.h>
#include <iostream>

using namespace std;
/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        vector<set<char>>columnCheck(board[0].size());
        vector<set<char>>rowCheck(board.size());
        vector<vector<set<char>>>squareCheck(board.size()/3,vector<set<char>>(board.size()/3));

        for (int i = 0; i < board.size(); i++)
            for (int j = 0; j < board[i].size(); j++){

                if(!isdigit(board[i][j]))continue;

                if (columnCheck[j].count(board[i][j]) 
                || rowCheck[i].count(board[i][j])
                || squareCheck[i/3][j/3].count(board[i][j])){
                    return false;
                }
                columnCheck[j].emplace(board[i][j]);
                rowCheck[i].emplace(board[i][j]);   
                squareCheck[i/3][j/3].emplace(board[i][j]);
            }
        return true;
    }
};
// @lc code=end

