class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 1. Count frequencies of each element
        unordered_map<int, int> mp;
        for (int num : nums) {
            mp[num]++;
        }

        // 2. Create buckets where index = frequency
        // Size is nums.size() + 1 because max frequency can be nums.size()
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto it : mp) {
            int element = it.first;
            int frequency = it.second;
            buckets[frequency].push_back(element);
        }

        // 3. Collect top k frequent elements from right to left
        vector<int> res;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            for (int num : buckets[i]) {
                res.push_back(num);
                if (res.size() == k) {
                    return res;
                }
            }
        }
        
        return res;
    }
};
