class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int rows = matrix.size();
    int cols = matrix[0].size();
    
    int i = 0, j = cols - 1; 
    
    while(i < rows && j >= 0) {
        int curr = matrix[i][j];
        if(curr == target) return true;
        else if(curr > target) j--; 
        else i++; 
    }
    return false;
    }
};