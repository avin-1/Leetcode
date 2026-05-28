class Solution {
    int findMaxIdx(vector<int>& nums, int mid) {
        int idx = -1, maxi = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > maxi) {
                maxi = nums[i];
                idx = i;
            }
        }
        return idx;
    }

public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxIdx = findMaxIdx(mat[mid], mid);
            int top = mid - 1 >= 0 ? mat[mid - 1][maxIdx] : -1;
            int bottom = mid + 1 < n ? mat[mid + 1][maxIdx] : -1;
            if (mat[mid][maxIdx] >= top && mat[mid][maxIdx] >= bottom) {
                return {mid, maxIdx};
            } else if (mat[mid][maxIdx] <= bottom) {
                low = mid + 1;
            } else
                high = mid - 1;
        }
        return {-1, -1};
    }
};

auto init = []() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return '$';
}();