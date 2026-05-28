class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int ans = -1;
        // we have to find a smallest divisor such that after the division the
        // sum of ans should be less than or equal to threshold

        int maxi = *max_element(nums.begin(), nums.end());
        int sum = 0;
        int low = 1;
        int high = maxi;
        int size = nums.size();
        while (low<=high) {
            int mid = low+(high-low)/2;
            sum = 0;
            for (int i = 0; i < size; i++) {
                sum += (nums[i] + mid - 1) / mid;
            }
            if (sum <= threshold){
                 ans = mid;
                 high = mid-1;
           }
           else{
                low = mid+1;
            }
        }
        return ans;
    }
};