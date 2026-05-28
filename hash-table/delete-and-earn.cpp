class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxNum = *max_element(nums.begin(), nums.end());
    vector<int> points(maxNum + 1, 0);
    for (int i : nums)
        points[i] += i;  

    vector<int> dp(maxNum + 1, 0);
    dp[0] = 0;
    dp[1] = points[1];

    for (int i = 2; i <= maxNum; i++)
        dp[i] = max(points[i] + dp[i - 2], dp[i - 1]);

    return dp[maxNum];
    }
};