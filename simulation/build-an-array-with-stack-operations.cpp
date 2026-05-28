class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {

        // lets assume we have sorted target array 
        // okay so we have to define some rules for push and the pop
        // so if we encounter the target[i] = next int then keep it
        // if the next element is not needed then pop it

        vector<string> res;

        stack<int> st;

        int str = 1;
        int i = 0;

        while(str <= n && i < target.size()) {

            if(target[i] == str) {

                while(!st.empty() && (i > 0 && st.top() != target[i - 1])) {
                    st.pop();
                    res.push_back("Pop");
                }

                // now we can push the element 
                st.push(target[i]);
                res.push_back("Push");

                i++;
                str++;
            }

            // if target is not equals to the stream int then just push and pop
            else {

                st.push(str);
                res.push_back("Push");

                st.pop();
                res.push_back("Pop");

                str++;
            }
        }

        return res;
    }
};