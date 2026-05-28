class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_set<int> blocked(restricted.begin(), restricted.end());
        vector<bool> visited(n, false);

        queue<int> q;
        q.push(0);
        visited[0] = true;

        int ans = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans++;

            for (int nei : adj[node]) {
                if (!visited[nei] && !blocked.count(nei)) {
                    visited[nei] = true;
                    q.push(nei);
                }
            }
        }
        return ans;
    }
};
