class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
      int n = arr.size();
      int i=0,h = 0;
      int cnt =0;
      int sum = 0;
      while(i<k){
            sum += arr[i];
            i++;
        }
        
        if(sum/k>=threshold){
            cnt++;
        }
        while(i<n){
            sum -= arr[h];
            h++;
            sum+=arr[i];
            i++;
            if(sum/k>=threshold){
                cnt++;
            }

        }
        return cnt;

    }
};