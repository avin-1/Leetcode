class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        // so we have to move 
        //  so what we can do is calculate teh frequencies of the L R and empty and make the 
        //  we can just iterate through the array and set the empty  the most freq one

        // r=1
        // L = 2
        // empty = 4
        int n = moves.length();
        int empty = 0;
        int r = 0;
        int l = 0;
        for(int i = 0 ;i<n;i++){
            if(moves[i]=='L'){
                l++;
            }else if(moves[i]=='R'){
                r++;
            }else{
                empty++;
            }
        }
        if(r>=l){
            r = r+empty;
            return r-l;
        }else{
            l = l+empty;
            int ans = l-r;
            return abs(ans);
        }
        return empty;
    }
};