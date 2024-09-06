/*
 * @lc app=leetcode id=959 lang=cpp
 *
 * [959] Regions Cut By Slashes
 */

// @lc code=start
class DisjointSet {
private:
    vector<int> parent, rank;
    int count;

public:
    DisjointSet(int n) : parent(n), rank(n, 0), count(n) {
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
            count--;
        }
    }

    int getCount() {
        return count;
    }
};

class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        DisjointSet ds(4 * n * n);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i > 0) ds.unite(getIndex(n, i-1, j, 2), getIndex(n, i, j, 0));
                if (j > 0) ds.unite(getIndex(n, i, j-1, 1), getIndex(n, i, j, 3));
                
                if (grid[i][j] != '/') {
                    ds.unite(getIndex(n, i, j, 0), getIndex(n, i, j, 1));
                    ds.unite(getIndex(n, i, j, 2), getIndex(n, i, j, 3));
                }
                if (grid[i][j] != '\\') {
                    ds.unite(getIndex(n, i, j, 0), getIndex(n, i, j, 3));
                    ds.unite(getIndex(n, i, j, 1), getIndex(n, i, j, 2));
                }
            }
        }
        
        return ds.getCount();
    }
    
private:
    int getIndex(int n, int row, int col, int pos) {
        return (row * n + col) * 4 + pos;
    }
};
// @lc code=end

