class Solution {
public:
    void sortColors(vector<int>& arr) {
        int low = 0;
        int high = arr.size() -1;
        int mid = 0;
        int temp = 0;

        while(mid<=high){
            if(arr[mid]==0){
                temp = arr[mid];
                arr[mid] = arr[low];
                arr[low] = temp;
                mid++;
                low++;
            }
            else if(arr[mid] ==1){
                mid++;
            }
            else{
                temp = arr[high];
                arr[high] = arr[mid];
                arr[mid] = temp;
                high--;
                
            }
        }

    }
};