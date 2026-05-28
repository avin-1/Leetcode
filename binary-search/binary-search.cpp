class Solution {
    int binarysearch(int low, int high, vector<int>& nums, int target) {
        if(low>high) return -1;
        // i as a answer pointer index
        int i =low + (high-low) / 2; // calculating mid of search space

        if (nums[i] == target) return i; // checking if mid is target

        // If not then
        // For greater than target
        if (target > nums[i]) {
            low = i + 1;
          return  binarysearch(low, high, nums, target);
        }
        // smaller than target
        if (target < nums[i]) {
            high = i - 1;
           return binarysearch(low, high, nums, target);
        }

        return -1;
    }

public:
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1) {
            if(target == nums[0]) return 0;
            else return -1;
        }
        int low = 0;
        int high = nums.size();
        int ind = -1;
        ind = binarysearch(low, high, nums, target);
        return ind;
    }
};