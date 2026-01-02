class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        multiset<char> st(s.begin(), s.end());
        vector<string> ans;
        string pre = "";

        for (int i = 0; i < t.size(); i++) {
            auto it = st.upper_bound(t[i]);
            if (it != st.end()) {
                string candidate = pre;   
                char bigger = *it;

                candidate += bigger;
                st.erase(it);
                for (char c : st) candidate += c;
                st.insert(bigger);

                ans.push_back(candidate);
            }

           
            auto match = st.find(t[i]);
            if (match == st.end()) break;

            pre += t[i];
            st.erase(match);
        }

        if (ans.empty()) return "";
        sort(ans.begin(), ans.end());
        return ans[0];
    }
};
