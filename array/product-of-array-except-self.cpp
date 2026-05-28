class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int pro = 1;
        int size = nums.size();
        int cnt = 0;
        int ind = -1;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                cnt++;
                ind = i;
                // we have index of element that is zero
                if (cnt > 1) {
                    vector<int> an(size, 0);
                    return an;
                }
            }else pro = nums[i] * pro;
        }
        // we have product of array now
        for (int i = 0; i < size; i++) {
            if(ind !=-1){
                if(nums[i]==0){
                    res.push_back(pro);
                }else res.push_back(0);
            }else{
                int ans = pro/nums[i];
                res.push_back(ans);
            }
        }
        return res;
    }
};