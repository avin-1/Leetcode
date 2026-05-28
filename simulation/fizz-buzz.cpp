class Solution {
public:
    vector<string> fizzBuzz(int n) {
        int cnt = 1;
        vector<string> ans;
        while(cnt<=n){
            if(cnt%3 == 0 && cnt%5 == 0){
                ans.push_back("FizzBuzz");
            }else if(cnt%3 == 0){
                ans.push_back("Fizz");
            }else if(cnt%5 == 0){
                ans.push_back("Buzz");
            }else{
                ans.push_back(to_string(cnt
                ));
            }
            cnt++;
        }
        return ans;
    }
};