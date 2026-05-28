class Solution {
    vector<vector<string>> ans;
    vector<string> board;

    bool isSafe(int r, int c, int n) {
        for(int i = 0; i < r; i++)
            if(board[i][c] == 'Q') return false;

        for(int i=r-1, j=c-1; i>=0 && j>=0; i--, j--)
            if(board[i][j] == 'Q') return false;

        for(int i=r-1, j=c+1; i>=0 && j<n; i--, j++)
            if(board[i][j] == 'Q') return false;

        return true;
    }

    void dfs(int r, int n) {
        if(r == n) {
            ans.push_back(board);
            return;
        }

        for(int c = 0; c < n; c++) {
            if(isSafe(r, c, n)) {
                board[r][c] = 'Q';
                dfs(r+1, n);
                board[r][c] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        board.assign(n, string(n, '.'));
        dfs(0, n);
        return ans;
    }
};