class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n  = nums.size();
        //finding break point
        long ind = 0;
        bool flag = false;
        for(int i = n-2;i>=0;i--){
            if (nums[i]<nums[i+1]){
                ind = i;
                flag= true;
                break;
            }
        }
        if(flag == false){
            reverse(nums.begin(),nums.end());
            return;
        }

        for(int i= n-1;i>ind;i--){
            if(nums[i]>nums[ind]){
                swap(nums[i],nums[ind]);
                break;
            }
        }
        reverse(nums.begin()+ind+1,nums.end());
        
    }
};