class Solution {
    void dfs(vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j){
        // we have index to run dfs on 
        stack<pair<int,int>> st;
        st.push({i,j});
        int r = grid[0].size();
        int c = grid.size();
        while(!st.empty()){
            auto [x,y] = st.top();
            st.pop();
            visited[x][y]=1;
            if(x<c-1&&grid[x+1][y]=='1'&&visited[x+1][y]==0){
                visited[x+1][y]=1;
                st.push({x+1,y});
            }
            if(x>0&&grid[x-1][y]=='1'&&visited[x-1][y]==0){
                visited[x-1][y]=1;
                st.push({x-1,y});
            }
            if(y>0&&grid[x][y-1]=='1'&&visited[x][y-1]==0){
                visited[x][y-1]=1;
                st.push({x,y-1});
            }
             if(y<r-1&&grid[x][y+1]=='1'&&visited[x][y+1]==0){
                visited[x][y+1]=1;
                st.push({x,y+1});
            }
        } 
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // first we check if the encountered 1 is visited or not if visisted then skip else run dfs on it and continiously mark them as visited.
         int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(!visited[i][j]&&grid[i][j]=='1'){
                    dfs(grid,visited,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};