class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        
      mergesort(nums,0,nums.size() - 1);
         
         
        return nums;
      
    }


    void merge(vector<int>& nums,int low,int mid,int high){
        int i = low;
        int j = mid+1;
   vector<int> res ;
        while(i<=mid&&j<=high){
            if(nums[i]<=nums[j]){
              res.push_back(nums[i]);
              i++;
            }else{
                res.push_back(nums[j]);
                j++;

            }
        }
        while(i<=mid){
            res.push_back(nums[i]);
            i++;
        }
        while(j<=high){
            res.push_back(nums[j]);
            j++;
        }
        for(int k = 0 ;k<res.size();k++){
            nums[low+k] = res[k];
         }
        
    }
   void mergesort(vector<int>& nums,int low,int high){
        if(low>=high) return;
         int mid =low + (high-low)/2;
         mergesort(nums,low,mid);
         mergesort(nums,mid+1,high);
        merge(nums,low ,mid,high);
         
    }
};