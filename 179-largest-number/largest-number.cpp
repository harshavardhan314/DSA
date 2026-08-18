bool cmp(string a,string b){
   return a+b>b+a;
}

class Solution {
public:

    string largestNumber(vector<int>& nums) {
        vector<string>vals;
        for(auto it:nums){
            vals.push_back(to_string(it));
        }
        sort(vals.begin(),vals.end(),cmp);
        string res="";
        for(auto it:vals){
            res+=it;
        }
        if(res[0]=='0' && res.back()=='0'){
            return "0";
        }
    
        return res;
    }
};