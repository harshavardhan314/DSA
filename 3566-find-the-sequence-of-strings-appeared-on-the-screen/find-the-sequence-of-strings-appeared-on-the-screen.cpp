class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string>ans;
        string prev_str="";
        for(auto it:target)
        {
            prev_str+="a";
            ans.push_back(prev_str);
            while(prev_str.back()!=it)
            {
                char prev=prev_str.back();
                prev++;
                if(prev>'z')prev='a';
                prev_str.pop_back();
                prev_str.push_back(prev);
                ans.push_back(prev_str);
            }
        }
        return ans;
        
    }
};