class Solution {
public:
vector<vector<int>> memo;
    int uniquePaths(int m, int n) {
        memo.assign(m, vector<int>(n, -1));
        return dp(m - 1, n - 1);
    }
    int dp(int i, int j) {
        if (i < 0 || j < 0) return 0;
        if (i == 0 && j == 0) return 1;

        if (memo[i][j] != -1) return memo[i][j];

        memo[i][j] = dp(i - 1, j) + dp(i, j - 1);
        return memo[i][j];
    }
};