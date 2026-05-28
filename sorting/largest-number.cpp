class Solution {
public:
    string largestNumber(vector<int>& nums) {
         auto big = [](int a, int b) -> bool {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    };

    sort(nums.begin(), nums.end(), big);

    string ans = "";
    for (int i : nums) {
        ans.append(to_string(i));
    }
    if (ans[0] == '0') return "0";

    return ans;
    }
};