class Solution {
public:
    int mirrorFrequency(string s) {
        map<int,int>mp_a;
        map<int,int>mp_i;
        for(auto it:s){
            if(it>='a' && it<='z')mp_a[it-'a']++;
            else{
                mp_i[it-'0']++;
            }
        }
        int ans=0;
        for(int i=0;i<13;i++){
           
            ans+=abs(mp_a[i]-mp_a[25-i]);
        }
        for(int i=0;i<5;i++){
            ans+=abs(mp_i[i]-mp_i[9-i]);
        }
        return ans;
        
    }
};