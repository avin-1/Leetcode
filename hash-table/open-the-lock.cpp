class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        if (dead.count("0000")) return -1;

        queue<string> q;
        unordered_set<string> vis;

        q.push("0000");
        vis.insert("0000");

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                string cur = q.front();
                q.pop();

                if (cur == target) return steps;

                for (int i = 0; i < 4; i++) {
                    char original = cur[i];

                    for (int d : {-1, 1}) {
                        char next = (original - '0' + d + 10) % 10 + '0';
                        cur[i] = next;

                        if (!dead.count(cur) && !vis.count(cur)) {
                            vis.insert(cur);
                            q.push(cur);
                        }
                    }

                    cur[i] = original; // restore
                }
            }
            steps++;
        }
        return -1;
    }
};
