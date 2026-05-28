class Solution {
public:
    int reverse(int x) {
        int k = 0;
        int n;

        while(x!=0){
            n = x%10;
            x=x/10;
            if (k > INT_MAX / 10 || (k == INT_MAX / 10 && n > 7)) return 0;
            if (k < INT_MIN / 10 || (k == INT_MIN / 10 && n < -8)) return 0;
            k = k*10 +n;

        }
        return k;
    }
};