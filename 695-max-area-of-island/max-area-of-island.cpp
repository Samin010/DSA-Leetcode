class Solution {
    int max_area(int r, int c, vector<vector<int>>& grid,
                 vector<vector<int>>& vis) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int ans = 1;
        q.push({r, c});
        vis[r][c] = 1;
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] &&
                    grid[nx][ny] == 1) {
                    ans++;
                    vis[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        return ans;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!vis[i][j] && grid[i][j] == 1) {
                    int val = max_area(i, j, grid, vis);
                    ans = max(ans, val);
                }
            }
        }
        return ans;
    }
};