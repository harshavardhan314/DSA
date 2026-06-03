class Solution {
public:
    int openLock(vector<string>& deadends, string target) {

        queue<pair<string, int>> q;
        q.push({"0000", 0});
        map<string, int> mp;
        for (auto it : deadends) {
            mp[it]++;
        }
        set<string> vis;
        vis.insert("0000");
        while (!q.empty()) {

            string curr = q.front().first;
            int ops = q.front().second;

            q.pop();
            if (curr == target) {
                return ops;
            }
            if (mp.find(curr) != mp.end()) {
                continue;
            }

            for (int i = 0; i < curr.size(); i++) {
                int curr_val = curr[i] - '0';

                string addStr = curr;
                addStr[i] = ((curr_val + 1) % 10) + '0';

                if (vis.find(addStr) == vis.end()) {
                    vis.insert(addStr);
                    q.push({addStr, ops + 1});
                }

                string subStr = curr;
                subStr[i] = ((curr_val - 1 + 10) % 10) + '0';

                if (vis.find(subStr) == vis.end()) {
                    vis.insert(subStr);
                    q.push({subStr, ops + 1});
                }
            }
        }
        return -1;
    }
};