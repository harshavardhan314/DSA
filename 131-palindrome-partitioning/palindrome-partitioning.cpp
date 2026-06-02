bool is_palindrom(string &s){
    string new_string=s;
    reverse(new_string.begin(),new_string.end());
    return s==new_string;
}


void rec(int idx,string &s,vector<vector<string>>&res,vector<string>&vals){

    int n=s.size();
    string temp;
    if(idx>=n){
        
        res.push_back(vals);
        return;
    }

    for(int i=idx;i<n;i++){
        temp.push_back(s[i]);
        if(is_palindrom(temp)) {
            vals.push_back(temp);
            rec(i+1,s,res,vals);
            vals.pop_back();
            }
    }

}
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>vals;
        rec(0,s,res,vals);
        return res;
    }
};