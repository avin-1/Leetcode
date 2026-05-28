class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> altitude;
        altitude.push_back(0);
        // next element in vector will be i and gain[i];
        // how will i implement this
        int a = 0;
        for(int i = 0;i<gain.size();i++){
            altitude.push_back( altitude[a]+gain[i]);
            a++;
        }
        return *max_element(altitude.begin(),altitude.end());
    }
};