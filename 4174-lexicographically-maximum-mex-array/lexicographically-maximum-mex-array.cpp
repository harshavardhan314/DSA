class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n=nums.size();
        vector<int>suffix(n,0);
        set<int>st;
        int req=0;
        for(int i=n-1;i>=0;i--){
            st.insert(nums[i]);
            while(!st.empty() && st.find(req)!=st.end()){
                st.erase(req);
                req++;
                
            }
            suffix[i]=req;

        }
        
        vector<int>ans;
        set<int>have;
        int want=suffix[0];
        int curr=0;
        for(int i=0;i<n;i++){
            have.insert(nums[i]);
            while(!have.empty() && have.find(curr)!=have.end()){
                have.erase(curr);
                curr++;
            }
            if(curr==want){
                ans.push_back(curr);
                if(i+1<n){
                    want=suffix[i+1];
                    curr=0;
                    have.clear();
                }
            }


        }
        return ans;
    }
};