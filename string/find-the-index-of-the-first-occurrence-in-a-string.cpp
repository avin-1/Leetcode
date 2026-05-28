class Solution {
public:
    int strStr(string haystack, string needle) {

        // Edge case
        if (needle.empty()) {
            return 0;
        }

        int n = haystack.length();
        int m = needle.length();

        // Traverse all possible starting indices
        for (int i = 0; i <= n - m; i++) {

            int j = 0;

            // Compare characters
            while (j < m && haystack[i + j] == needle[j]) {
                j++;
            }

            // Full match found
            if (j == m) {
                return i;
            }
        }

        return -1;
    }
};