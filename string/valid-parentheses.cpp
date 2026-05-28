class Solution {
public:
    bool isValid(string s) {

        stack<char> st;
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else {
                if (st.empty())
                    return false; // 1. empty check
                char c = st.top();
                st.pop(); // 2. pop after match
                if ((c == '(' && ch != ')') || (c == '{' && ch != '}') ||
                    (c == '[' && ch != ']'))
                    return false;
            }
        }
        return st.empty(); // 3. final check
    }
};