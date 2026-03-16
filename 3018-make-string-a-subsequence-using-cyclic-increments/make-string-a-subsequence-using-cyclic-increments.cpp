class Solution {
public:
    bool canMakeSubsequence(string s, string req) {

        int i=0;
        int j=0;
        int n=s.size();
        int m=req.size();
        while (i<n && j<m){
            char next_char=s[i]+1;
            if(next_char>'z')next_char='a';
            if(s[i]==req[j] || next_char == req[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j!=m)return false;
        return true;
        
        
    }
};