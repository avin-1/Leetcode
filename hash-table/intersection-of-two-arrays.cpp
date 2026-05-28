#include <set>
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
         set<int> res;
        vector<int> v;
        for (int num1 : nums1) {
            for (int num2 : nums2) {
                if (num1 == num2) {
                    res.insert(num1);
                }
            }
        }
        for (int num : res) {
            v.push_back(num);
        }

        return v;

            }
};