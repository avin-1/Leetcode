class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int maxi = 0;
        //loop through array
        /* while looping we will increase max if the num[i]==1 and set max to 0 if num[i]==0  at every iteration we will update ans such that ans = max of max,ans*/
        for(int i = 0;i<nums.size();i++){
            if(nums[i]==1){
                maxi++;
            }if(nums[i]==0){
                maxi = 0;
            }
            ans = max(maxi,ans);
        }
        return ans;
    }
};