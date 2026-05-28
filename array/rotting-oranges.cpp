class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        // Find all the rotten oranges and count fresh oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        // We have all the rotten oranges
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        int minutes = -1;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                pair<int, int> p = q.front();
                int x = p.first;
                q.pop();
                int y = p.second;
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d], ny = y + dy[d];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        grid[nx][ny] == 1) {
                        grid[nx][ny] = 2;
                        fresh--;
                        q.push({nx, ny});
                    }
                }
            }
            minutes++;
        }
        if (fresh > 0) {
            return -1;
        }
        return max(0, minutes);
    }
};