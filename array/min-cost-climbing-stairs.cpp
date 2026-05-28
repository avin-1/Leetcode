class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int size = cost.size();
        int prev = cost[0];
        int curr = cost[1];
        for (int i = 2; i < size; i++) {
            int c = cost[i] + min(curr, prev);
            prev = curr;
            curr = c;
        }
        return min(curr, prev);
    }
};