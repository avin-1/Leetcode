class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
    int n = nums.size();
    vector<long long> prefix(n);
    
    prefix[0] = nums[0];
    for(int i = 1; i < n; i++)
        prefix[i] = prefix[i-1] + nums[i];

    long long total = prefix[n-1];

    unordered_map<long long, int> right, left;

    for(int i = 0; i < n-1; i++)
        right[prefix[i]]++;

    int ans = 0;

    if(total % 2 == 0)
        ans = right[total/2];

    for(int j = 0; j < n; j++){
        long long delta = k - nums[j];

        if(j > 0){
            left[prefix[j-1]]++;
            right[prefix[j-1]]--;
        }

        long long newTotal = total + delta;

        if(newTotal % 2 == 0){
            long long target = newTotal / 2;

            int count = 0;

            count += left[target];
            count += right[target - delta];

            ans = max(ans, count);
        }
    }

    return ans;
}
};