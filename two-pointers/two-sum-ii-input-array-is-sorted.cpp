class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int k) {
        int n = nums.size();
        int right  = 0,left = n-1;
        while(right<left){
            if(nums[right]+nums[left]==k){
                return vector<int> {right+1,left+1};
            }
            else if(nums[right]+nums[left]>k){
                left--;
            }else if(nums[right]+nums[left]<k){
                right++;
            }
        }
        return vector<int> {-1,-1};
    }
};