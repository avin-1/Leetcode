class Solution {
    vector<vector<int>> answer;

    void helper(vector<int>& nums, vector<int>& localresult, unordered_map<int,int>& mp) {
        if (localresult.size() == nums.size()) {
            answer.push_back(localresult);
            return;
        }

        for (auto &p : mp) {
            int key = p.first;
            int &count = p.second;

            if (count > 0) {
                localresult.push_back(key);
                count--;

                helper(nums, localresult, mp);

                count++;
                localresult.pop_back();
            }
        }
    }

public:
    vector<vector<int>> permute(vector<int>& nums) {
        unordered_map<int,int> mp;

        for (int i : nums) {
            mp[i]++;
        }

        vector<int> localresult;
        helper(nums, localresult, mp);

        return answer;
    }
};