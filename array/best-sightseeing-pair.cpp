class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        // precompute and store the max value[j]-j and store it
        int n = values.size();
        if(n<2) return values[0]+values[1]+0-1;
        vector<int> suffixMax(n);
        suffixMax[n-1] = values[n-1]-(n-1);
        for(int i = n-2;i>=0;i--){
            suffixMax[i] = max(suffixMax[i+1],values[i]-i);
        }
        int maxScore = INT_MIN;
        for(int i = 0;i<n-1;i++){
            // compute values[i]+i+suffixmax[i+1]; and take max of maxScore and this compute
            int compute = values[i]+i+suffixMax[i+1];
            maxScore = max(maxScore,compute);
        }
        return maxScore;
    }
};