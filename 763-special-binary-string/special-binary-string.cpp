class Solution {
public:
    string makeLargestSpecial(string s) {

        int sum=0;
        int st=0;
        vector<string>sp;

        for(int i=0;i<s.size();i++){
            sum+=s[i]=='1'?1:-1;
            if(sum==0){
                string inner=s.substr(st+1,i-st-1);
                sp.push_back("1"+makeLargestSpecial(inner)+"0");
                st=i+1;
            }
        }
        sort(sp.rbegin(),sp.rend());
        string res="";
        for(auto it:sp){
            res+=it;
        }
        return res;

        
    }
};