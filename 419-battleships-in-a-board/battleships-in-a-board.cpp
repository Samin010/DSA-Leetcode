class Solution {
    void solve(int r, int c, int n, int m, vector<vector<char>>& grid,
               vector<vector<int>>& vis) {
        vis[r][c] = 1;
        // mark the row
        int x = c + 1;
        int y = r + 1;
        if (x < m && grid[r][x] == 'X') {
            while (x < m && !vis[r][x] && grid[r][x] == 'X') {
                vis[r][x] = 1;
                x++;
            }
        }
        // mark the column
        else if (y < n && grid[y][c] == 'X') {
            while (y < n && !vis[y][c] && grid[y][c] == 'X') {
                vis[y][c] = 1;
                y++;
            }
        }
    }

public:
    int countBattleships(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '.')
                    vis[i][j] = 1;
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'X' && !vis[i][j]) {
                    ans++;
                    solve(i, j, n, m, board, vis);
                }
            }
        }
        return ans;
    }
};