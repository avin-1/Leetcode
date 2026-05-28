class Solution {
public:

  std::string clean(const std::string& s) {
    std::string c;
    for (size_t i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (isalnum(ch)) {
                c += tolower(ch);
            }
    }
    return c;
}

bool palim(const std::string& s, int start, int end) {
    if (start >= end) return true; // Base case: all characters checked
    if (s[start] != s[end]) return false; // Mismatch found
    return palim(s, start + 1, end - 1); // Check next pair
}

bool isPalindrome(string& s) {
    std::string a = clean(s); // Clean the string
    int start = 0;
    int end = a.length() - 1;

    return palim(a, start, end); // Check if cleaned string is palindrome
}
};