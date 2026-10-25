
class Solution {
    bool dfs(vector<vector<int>>& grid, int row, int col) {
        int n = grid.size();
        int m = grid[0].size();
        if(row<0 ||col<0 ||row>= n || col >= m) {
            return false;
        }
        if(grid[row][col] == 1) {
            return true;
        }
        grid[row][col] = 1;
         bool a = dfs(grid, row + 1, col);
        bool b = dfs(grid, row - 1, col);
        bool c = dfs(grid, row, col + 1);
        bool d = dfs(grid, row, col - 1);
        return a && b && c&& d;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    if(dfs(grid, i, j)) {
                        count++;
                    }
                }
            }
        }
    return count;
    }
};
