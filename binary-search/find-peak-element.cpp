class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         int low = 0, high = nums.size() - 1;

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > nums[mid + 1]) {
            // Peak lies on the left (including mid)
            high = mid;
        } else {
            // Peak lies on the right
            low = mid + 1;
        }
    }
    return low; 
    }
};