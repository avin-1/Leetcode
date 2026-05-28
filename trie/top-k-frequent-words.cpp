class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        /*
        we can store each unique string somewhere and then for each string we
        can increase the frequency we can use unordered map for this mapping the
        string and the integer then return the top k max keys descending by
        frequencies
        */
        // store the unique strings here
        unordered_map<string, int> mp;
        for (int i = 0; i < words.size(); i++) {
            string s = words[i];
            // now we have each element
            // check if it is in the mp already and if not then push it and if
            // yes then increase its value++;
            if (mp.find(s) != mp.end()) {
                mp[s]++;
            } else {
                mp.insert({s, 1});
            }
        }
        // now we have elements and their frequncy;
        vector<pair<string, int>> vec;
        for (auto it : mp) {
            pair<string, int> p = {it.first, it.second};
            vec.push_back(p);
        }
        // now we have pairs stored in the vector
        // we have to sort it out
        sort(vec.begin(), vec.end(), [](auto& a, auto& b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }

            return a.second > b.second;
        });
        // we have now sorted the array
        // make a new result array
        // making index i so we will iterate from the size-k- to the size-1 and
        // store the vec[i].first
        int size = vec.size();
        int ind = size - k - 1;
        vector<string> res;

        for (int i = 0; i < k; i++) {
            res.push_back(vec[i].first);
        }

        return res;
    }
};