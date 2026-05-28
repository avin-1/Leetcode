class Solution {
   int computedays(vector<int>& weight, int mid) {
    int cnt = 1; 
    int w = 0;
    for (int x : weight) {
        if (w + x > mid) {
            cnt++;
            w = 0;
        }
        w += x;
    }
    return cnt;
}


public:
    int shipWithinDays(vector<int>& weights, int days) {
         int low = *max_element(weights.begin(), weights.end()); // must fit biggest package
    int high = accumulate(weights.begin(), weights.end(), 0); // all in 1 day
    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int d = computedays(weights, mid);

        if (d <= days) {
            ans = mid;       // possible answer
            high = mid - 1;  // try smaller
        } else {
            low = mid + 1;   // need bigger capacity
        }
    }
    return ans;
    }
};