#include <vector>
#include <set>

/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<set<char>>>check;
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[i].size(); i++){
                if (i>0){
                    if (check[i-1][j].count(board[i][j])){
                        return false;
                    }
                    check[i][j] = 
                    
                }
                else{
                    check[i-1][j].count(board[i][j]);
                }
                if (i>0 && check[i-1][j].count(board[i][j]))
                {
                    /* code */
                }
                
            }
            
        }
        
    }
};
// @lc code=end

