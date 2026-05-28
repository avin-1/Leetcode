class Solution {
    int countzeros(string& s) {
        int res = 0;
        for (char c : s) if (c == '0') res++;
        return res;
    }
    int countones(string& s) {
        int res = 0;
        for (char c : s) if (c == '1') res++;
        return res;
    }

    vector<vector<vector<int>>> dp;

    int helper(vector<string>& strs, int m, int n, int i) {
        if (i >= strs.size()) return 0;
        if (dp[i][m][n] != -1) return dp[i][m][n];

        int zeros = countzeros(strs[i]);
        int ones  = countones(strs[i]);

        int isOut = helper(strs, m, n, i + 1);
        int isIn  = 0;
        if (zeros <= m && ones <= n)
            isIn = 1 + helper(strs, m - zeros, n - ones, i + 1);

        return dp[i][m][n] = max(isIn, isOut);
    }

public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        dp.assign(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return helper(strs, m, n, 0);
    }
};