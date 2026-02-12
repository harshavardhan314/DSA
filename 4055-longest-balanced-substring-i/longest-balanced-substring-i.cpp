class Solution {
public:
    int longestBalanced(string s) {

        int ans=0;
        for(int i=0;i<s.size();i++){
            vector<int>freq(26,0);
            for(int j=i;j<s.size();j++){
                freq[s[j]-'a']++;

                bool found=true;
                
                for(int k=0;k<26;k++){ 
                    if(freq[k]>0 && freq[k]!=freq[s[j]-'a'])found=false;
                }
                if(found)ans=max(ans,j-i+1);
            }
        }
        return ans;

        
    }
};