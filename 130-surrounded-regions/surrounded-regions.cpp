class Solution {
    void dfs(vector<vector<char>>& board,int r,int c){
        int m = board.size();
        int n = board[0].size();
        if(r < 0 || c < 0 || r >= m || c >= n) {
            return;
        }
        if(board[r][c] != 'O') {
            return;
        }
        board[r][c] = '#';
        dfs(board, r-1, c);
        dfs(board, r+1, c);
        dfs(board, r, c-1);
        dfs(board, r, c+1);
    }

public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int j=0;j<n;j++){
            if(board[j][0]=='O'){
                dfs(board,j,0);
            }
            if(board[j][m-1]=='O'){
                dfs(board,j,m-1);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                dfs(board,0,i);
            }
            if(board[n-1][i]=='O'){
                dfs(board,n-1,i);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                        board[i][j]='O';
                }
            }
        }
    }
};