class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n=nums.size();

        vector<int>best_mex(n,0);
        int mex=0;
        map<int,int>mp;
        for(int i=n-1;i>=0;i--){
            mp[nums[i]]++;
            while(mp.find(mex)!=mp.end()){
                mex++;
            }
            best_mex[i]=mex;
        }
        
        mp.clear();
        int want=best_mex[0];
        mex=0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            while(mp.find(mex)!=mp.end()){
                mex++;
            }
            if(mex==want){
                ans.push_back(mex);
                mex=0;
                mp.clear();
                if(i+1<n)
                want=best_mex[i+1];
            }

        }
        return ans;

        
    }
};