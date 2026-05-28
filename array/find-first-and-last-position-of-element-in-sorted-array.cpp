class Solution {
public:
   vector<int> searchRange(vector<int>& nums, int target) {
    int low = 0;
    int high = nums.size() - 1;
    int start = -1;
    int end = -1;
    int i = -1;

    // Standard binary search to find any occurrence of target
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) {
            i = mid;
            break;
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (i == -1) return {start, end};

   
    int j = i;
    while (j >= 0 && nums[j] == target) {
        start = j;
        j--;
    }

    j = i;
    while (j < nums.size() && nums[j] == target) {
        end = j;
        j++;
    }

    return {start, end};
}

};