class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> ans(n);

        unordered_map<int, vector<int>> mp;

        // Group indices by value
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        for (auto &it : mp) {
            vector<int>& idx = it.second;

            long long totalSum = 0;
            for (int x : idx) {
                totalSum += x;
            }

            long long prefixSum = 0;
            int m = idx.size();

            for (int i = 0; i < m; i++) {
                long long current = idx[i];

                long long left = current * i - prefixSum;

                long long right =
                    (totalSum - prefixSum - current)
                    - current * (m - i - 1);

                ans[current] = left + right;

                prefixSum += current;
            }
        }

        return ans;
    }
};