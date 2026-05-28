class Solution {
    int computeBouqutes(int day, vector<int>& bloomDay, int m, int k) {
        int bouquets = 0;
        int cnt = 0;
        int size = bloomDay.size();
        for (int i = 0; i < size; i++) {
            if (bloomDay[i] <= day) {
                cnt++;
            } else {
                cnt = 0;
            }
            if (cnt == k) {
                bouquets++;
                cnt = 0;
            }
        }
        return bouquets;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int size = bloomDay.size();
        if ((long long)m * k > (long long)size) {
            return -1;
        }

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        if (low == high) {
            return low;
        }
        int ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int b = computeBouqutes(mid, bloomDay, m, k);
            if (b == m) {
                ans = mid;
                high = mid - 1;
            } else if (b > m) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};