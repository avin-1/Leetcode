class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
     int n = nums.size();
    if (n < 3) return 0;  // Handle edge cases

    long long maxDiff = 0, maxTripletValue = 0;
    int maxNum = nums[0];

    for (int j = 1; j < n - 1; j++) {  // Ensure j + 1 is within bounds
        maxDiff = max(maxDiff, (long long)maxNum - nums[j]);
        maxTripletValue = max(maxTripletValue, maxDiff * nums[j + 1]);
        maxNum = max(maxNum, nums[j]);
    }

    return maxTripletValue;     
    }
};