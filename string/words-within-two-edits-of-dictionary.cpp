class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int qSize = queries.size();
        int dictSize = dictionary.size();
        vector<string> ans;
        for(int i = 0;i<qSize;i++){
            string q = queries[i];
            // we have each string now
            // match that each string with every other string 
            for(int j=0;j<dictSize;j++){
                string d = dictionary[j];
                int diff = 0;
                for(int k = 0;k<q.size();k++){
                    if(q[k]!=d[k]){
                        diff++;
                    }
                    if(diff>2){
                        break;
                    }
                }
                if(diff<=2){
                    ans.push_back(q);
                    break;
                }
            }
        }
        return ans;
    }
};