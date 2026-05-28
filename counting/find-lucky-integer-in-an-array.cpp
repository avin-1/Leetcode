class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> mp;
        vector<int> ans={-1};
        for(int i = 0;i<arr.size();i++){
            // insert all elements with 0 frequency
            mp.insert({arr[i],0});
        }
        for(int i = 0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(int i = 0;i<arr.size();i++){
            auto it = mp.find(arr[i]);
            if(it->second==arr[i]){
                ans.push_back(arr[i]);
            }
            else{
                continue;
            }
        }
        return *max_element(ans.begin(),ans.end());
    }
};