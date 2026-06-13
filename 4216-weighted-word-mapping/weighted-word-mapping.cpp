class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& w) {
        string res="";
        for(auto it:words){
            int weight=0;
            for(int i=0;i<it.size();i++){
                int val=(it[i]-'a');
                weight+=w[val];
            }
            int val=weight%26;

            char rev_char='z'-(val);
            res.push_back(rev_char);

        }
        return res;
        
    }
};