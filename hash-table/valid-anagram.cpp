class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> sm, tm;
        for (char c : s) {
            if (sm.contains(c)) sm[c]++;
            else sm[c] = 1;
        }
        for (char c: t) {
            if (tm.contains(c)) tm[c]++;
            else tm[c] = 1;
        }
        for (auto [c, v] : sm) {
            if (!tm.contains(c)) return false;
            else if (tm[c] != sm[c]) return false;
        }
        for (auto [c, v] : tm) {
            if (!sm.contains(c)) return false;
            else if (tm[c] != sm[c]) return false;
        }
        return true;
    }
};