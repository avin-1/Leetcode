#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

class Solution {
    // This will return the index for the closest 
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

    int solve(int i, int j, vector<int>& nums) {
        // Base case: if we are already at the destination, cost is 0
        if (i == j) return 0;

        int next_index = 0;
        if (j > i) {
            next_index = i + 1; // Look ahead without overwriting 'i' yet
        }
        else if (j < i) {
            next_index = i - 1; // Look behind without overwriting 'i' yet
        }

        // Calculate the cost for this single step
        int current_step_cost = 0;
        if (closest(i, nums) != next_index) {
            current_step_cost = abs(nums[i] - nums[next_index]);
        } else {
            current_step_cost = 1;
        }

        // Recursively calculate the rest of the path and add it up
        return current_step_cost + solve(next_index, j, nums);
    }

public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> res;
        for (int i = 0; i < queries.size(); i++) {
            vector<int> temp = queries[i];
            int r = solve(temp[0], temp[1], nums);
            res.push_back(r);
        }
        return res;
    }
};
