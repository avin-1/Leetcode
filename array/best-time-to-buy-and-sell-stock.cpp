class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        int mini = INT_MAX;
        int ans = 0;
        for(int i = 0;i<size;i++){
            if(prices[i]<mini){
                mini = prices[i];
            }
            if(prices[i]>mini){
                int sub = prices[i]-mini;
                ans = max(sub,ans);
            }
        }
        if(ans == 0){
            return 0;
        }
        return ans;
    }
};