class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
    int start = 0;  
    long long totalCost = 0;  
    int maxFreq = 1; 
    for (int end = 1; end < nums.size(); ++end) {
       
        totalCost += static_cast<long long>(nums[end] - nums[end - 1]) * (end - start); 
        while (totalCost > k) {
            totalCost -= nums[end] - nums[start];
            ++start;
        }   
        maxFreq = max(maxFreq, end - start + 1);
    }
    return maxFreq;
    }
};