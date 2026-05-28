class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
    
    // If the array has 0 or 1 elements, it is considered sorted
    if (n <= 1) return true;
    
    // Variable to track the number of breaks in order
    bool foundBreak = false;

    for (int i = 0; i < n; i++) {
        // Check if the current element is greater than the next
        if (nums[i] > nums[(i + 1) % n]) {
            if (foundBreak) {
                // If we find more than one break, return false
                return false;
            }
            foundBreak = true; // Mark that we found a break
        }
    }

    return true;
    }
};