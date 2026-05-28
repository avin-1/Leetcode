class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
         if (strs.empty()) return "";

    string ans = strs[0];
    int ansSize = ans.size();

    for (int i = 1; i < strs.size(); i++) {
        int k = 0;
        while (k < ansSize && k < strs[i].size() && ans[k] == strs[i][k]) {
            k++;
        }
        ans = ans.substr(0, k);
        ansSize = ans.size();
        if (ansSize == 0) return "";
    }
    return ans;
    }
};