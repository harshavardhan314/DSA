class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& a, vector<int>& b) {

        map<int,int>mp1;
        map<int,int>mp2;

        vector<int>ans;
        int n=a.size();

        for(int i=0;i<n;i++){
            mp1[a[i]]++;
            mp2[b[i]]++;
            int cnt=0;
            for(auto it:mp1){
                if(mp2.find(it.first)!=mp2.end())cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
        
    }
};