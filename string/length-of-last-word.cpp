class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        int len = s.length();
        int i = len-1;
        while(i>=0&&s[i]==' '){
            i--;
        }
        while(i>=0&&s[i]!=' '){
            ans++;
            i--;
        }
        return ans;
    }
};