class Solution {
public:
    int maxProduct(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return nums[0];

    // Standard Kadane's uses one var, Product Kadane's needs two
    int globalmax = nums[0];
    int localmax = nums[0];
    int localmin = nums[0];

    for (int i = 1; i < n; i++) {
        // If current number is negative, it swaps the potential for max and min
        if (nums[i] < 0) {
            swap(localmax, localmin);
        }

        // Kadane's core: "Do I extend the previous subarray or start fresh here?"
        localmax = max(nums[i], localmax * nums[i]);
        localmin = min(nums[i], localmin * nums[i]);

        // Update the overall winner
        globalmax = max(globalmax, localmax);
    }

    return globalmax;
}

};