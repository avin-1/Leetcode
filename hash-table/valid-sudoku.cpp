class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<string> c;
        int n = 0;
        for(int i = 0;i<9;i++){
            for(int j = 0;j<9;j++){
                char ch = board[i][j];
                if(ch != '.'){
                    n++;
                    string row = "row"+to_string(i)+ch;
                    string col = "col"+to_string(j)+ch;
                    int bidx = (i/3)*3+j/3;
                    string block = "block"+to_string(bidx)+ch;
                    c.insert(row);
                    c.insert(col);
                    c.insert(block);

                }
            }
        }
        return c.size()==3*n;
    }
};