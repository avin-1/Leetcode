class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // General Idea is to push all zeros in queue then scan surrounding
        // elements of 1 then make that 1's dist 1 then push those ones in queue
        // i,j == one element
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    q.push({i, j});
                    dist[i][j] = 0;
                }
            }
        }
        
        // Now for scanning sorrunding elements of 0s we need a mech
        // i.e
        // vector<int> dx={-1,1,0,0}; up and down
        // vector<int> dy={0,0,-1,1}; left and right
        vector<int> dx = {-1, 1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        while (!q.empty()) {
                auto [x, y]= q.front();
                q.pop();
                // we have current now scan surrounding elements
                for (int d = 0; d < 4; d++) {
                    int nx = x + dx[d],
                        ny = y + dy[d]; // First it will go up then down left and then right
                    if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                        dist[nx][ny] == -1) {
                        dist[nx][ny] = dist[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
            return dist;
    }
};