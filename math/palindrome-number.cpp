class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) return false;

        int number = x;
        int reversed = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Check for overflow before it happens
            if (reversed > (INT_MAX - digit) / 10) {
                return false; // It will overflow, so return false
            }

            reversed = reversed * 10 + digit;
        }

        // Check if the original number is the same as the reversed number
        return reversed == number;
    }
};
