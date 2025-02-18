#include <bits/stdc++.h>
using namespace std;

int* row    = new int[1000001];
int* column = new int[1000001];
int* rowIndex = new int[1000001];
int* columnIndex = new int[1000001];
int n, m, arrSize;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        n = (int)mat.size();          
        m = (int)mat[0].size();       
        arrSize = (int)arr.size();
        
        memset(row, 0, n * sizeof(int));
        memset(column, 0, m * sizeof(int));
        memset(rowIndex,  0, n * sizeof(int));
        memset(columnIndex,  0, m * sizeof(int));
 
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++){
                rowIndex[mat[i][j]] = i;
                columnIndex[mat[i][j]] = j;
            }

        for(int i = 0; i < arrSize; i++){

            if(++row[rowIndex[arr[i]]] == m 
            || ++column[columnIndex[arr[i]]] == n) {
                return i; 
            }
        }
        return -1;
    }
};
