class Solution {
public:
    string reverseWords(string s) {
         string ans = "";
    int size = s.size() - 1;
    int low = size, high = size;

    while (low >= 0) {
        while (high >= 0 && s[high] == ' ') high--;
        low = high;
        while (low >= 0 && s[low] != ' ') low--;
        for (int j = low + 1; j <= high; j++) {
            ans.push_back(s[j]);
        }
        if (low > 0) ans.push_back(' ');
        high = low - 1;
    }
    if(ans[ans.size()-1]==' ') ans.pop_back();
    return ans;
    }
};