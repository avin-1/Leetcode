class Solution {
    int f(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
        if (i < 0 || j < 0)
            return 0;
        if (s[i] == t[j]) {
            if (dp[i][j] != -1)
                return dp[i][j];
            else
                return 1 + f(s, t, i - 1, j - 1, dp);
        }
        if (dp[i][j] != -1)
            return dp[i][j];

            int a = max(f(s, t, i - 1, j, dp), f(s, t, i, j - 1, dp));
            dp[i][j] = a;
            return a;
    }

public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int ans = f(text1, text2, n - 1, m - 1, dp);
        return ans;
    }
};