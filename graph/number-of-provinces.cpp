class Solution {
    vector<bool> isInSet;
    int ans = 0;

    void bfs(vector<vector<int>>& isConnected, int start) {
        int n = isConnected.size();
        queue<int> q;

        q.push(start);
        isInSet[start] = true;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();

            for (int i = 0; i < n; i++) {
                if (isConnected[cur][i] == 1 && !isInSet[i]) {
                    q.push(i);
                    isInSet[i] = true;
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        isInSet.assign(n, false); 

        for (int i = 0; i < n; i++) {
            if (!isInSet[i]) {
                ans++;
                bfs(isConnected, i);
            }
        }
        return ans;
    }
};
