class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
    /*  unordered_map<int, int> prefixSumCount;
    int sum = 0;
    int count = 0;
    prefixSumCount[0] = 1;
    for (int num : nums) {
        sum += num; 
        if (prefixSumCount.find(sum - k) != prefixSumCount.end()) {
            count += prefixSumCount[sum - k];
        }
        prefixSumCount[sum]++;
    }
    return count;
    */


    unordered_map<int,int> prefixSumCount;
   int count = 0;
   int sum = 0;
   prefixSumCount[0] =1 ;
   for(int i = 0;i<nums.size();i++){
    sum = sum + nums[i];
    if(prefixSumCount.find(sum-k)!=prefixSumCount.end()){
        count +=prefixSumCount[sum - k];
    }
    prefixSumCount[sum]++;

   }
    return count;
    }
};