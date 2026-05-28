class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
        Binary Search Intuition:
        - In a rotated sorted array, one half will always be sorted.
        - The smallest element in that sorted half will be its first element.
        - So:
            1) If left half [low..mid] is sorted → nums[low] is a candidate for min,
               then search in right half (mid+1).
            2) If right half [mid..high] is sorted → nums[mid] is a candidate for min,
               then search in left half (mid-1).
        - Keep track of the smallest seen so far in 'ans'.
    */
       int ans = INT_MAX;
       int low = 0;
       int high = nums.size()-1;
       while(low<=high){
        int mid = low+(high-low)/2;
        if(nums[low]<=nums[mid]){
            ans = min(ans,nums[low]);
            low = mid+1;
        }else if(nums[mid]<=nums[high]){
            ans = min(ans,nums[mid]);
            high = mid-1;
        }
       }
       return ans;
    }
};