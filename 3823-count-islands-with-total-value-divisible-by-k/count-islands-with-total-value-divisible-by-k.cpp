class Solution {
    long long dfs(vector<vector<int>>& grid, int row, int col) {
        int n = grid.size();
        int m = grid[0].size();
        if(row < 0 || col < 0 || row >= n || col >= m) {
            return 0;
        }
        if(grid[row][col] == 0) {
            return 0;
        }
        int val = grid[row][col];
        grid[row][col] = 0;
        long long a = dfs(grid, row + 1, col);
        long long b = dfs(grid, row - 1, col);
        long long c = dfs(grid, row, col + 1);
        long long d = dfs(grid, row, col - 1);
        return val + a + b + c + d;
    }
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] > 0) {
                    long long sum = dfs(grid, i, j);

                    if(sum % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};