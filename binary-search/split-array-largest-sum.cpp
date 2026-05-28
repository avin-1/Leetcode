class Solution {
    int countPartitions(vector<int> nums, int maxSum) {
        int partitions = 1;
        long long sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (sum + nums[i] <= maxSum) {
                sum += nums[i];
            } else {
                partitions++;
                sum = nums[i];
            }
        }
        return partitions;
    }

public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans = low;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int partitions = countPartitions(nums, mid);
            if (partitions <= k) {
                /* If partitions > k:

    That means mid is too small.

    Because even with greedy splitting, we had to create more than k partitions
    to keep each ≤ mid.

    So the true answer must be larger than mid → eliminate the left half → low =
    mid + 1. */
                ans = mid; // valid, try smaller maxSum
                high = mid - 1;
            } else {
                low = mid + 1; // too many partitions → need bigger maxSum
            }
        }
        return ans;
    }
};