class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //so we have to use kadane's a;go in this problem 
        //it states that carry the positive sum and drop if it goes below 0
        //lets start coding it
        int sum = 0;
        int ans = INT_MIN;

        for(int i = 0;i<nums.size();i++){
          sum +=nums[i];
          ans = max(sum,ans);
          if(sum<0) sum = 0;
        }
      
        return ans;
    }
};