class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<0){
            return false;
        }
        if(n==1){
           return true;
            }
        
        for(int i = 0;pow(2,i)<=n;i++){
        if(n == pow(2,i))
            return true;
        }

        return false;
    }

};