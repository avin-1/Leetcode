class Solution {
    double computehrs(vector<int>& piles, int k) {
        double hrs = 0;
        for (int i = 0; i < piles.size(); i++) {
            hrs += ceil((piles[i] + k - 1) / k);
        }
        return hrs;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int r = *max_element(piles.begin(), piles.end());
        int l = 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            double hrs = computehrs(piles, mid);
            if (hrs <= h) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};