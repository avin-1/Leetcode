#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
    // Keeping your exact closest logic
    int closest(int i, vector<int> &nums) {
        int left = INT_MAX;  
        int right = INT_MAX;
        
        if (i != 0) {        
            left = abs(nums[i] - nums[i - 1]);
        }
        if (i != nums.size() - 1) { 
            right = abs(nums[i] - nums[i + 1]);
        }
        
        if (left <= right) {
            return i - 1;
        } else {
            return i + 1;
        }
    }

public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        // 1. Create prefix arrays to store running totals of costs
        // We use long long to prevent integer overflow for large arrays
        vector<long long> pref_forward(n, 0);
        vector<long long> pref_backward(n, 0);
        
        // 2. Pre-calculate Forward costs (moving left to right)
        for (int i = 0; i < n - 1; i++) {
            int next_index = i + 1;
            int cost = (closest(i, nums) == next_index) ? 1 : abs(nums[i] - nums[next_index]);
            pref_forward[next_index] = pref_forward[i] + cost;
        }
        
        // 3. Pre-calculate Backward costs (moving right to left)
        for (int i = n - 1; i > 0; i--) {
            int next_index = i - 1;
            int cost = (closest(i, nums) == next_index) ? 1 : abs(nums[i] - nums[next_index]);
            pref_backward[next_index] = pref_backward[i] + cost;
        }
        
        // 4. Answer all queries instantly in O(1) time
        vector<int> res;
        res.reserve(queries.size());
        
        for (int i = 0; i < queries.size(); i++) {
            int start = queries[i][0];
            int end = queries[i][1];
            
            if (start <= end) {
                // Moving Left to Right: Subtract the starting total from the ending total
                res.push_back(pref_forward[end] - pref_forward[start]);
            } else {
                // Moving Right to Left: Subtract the starting total from the ending total
                res.push_back(pref_backward[end] - pref_backward[start]);
            }
        }
        
        return res;
    }
};
