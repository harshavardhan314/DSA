class Solution {
public:
    int getLength(vector<int>& nums) {
        
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            map<int,int>mp;
            map<int,int>freq;
            for(int j=i;j<n;j++){
                
                
                mp[nums[j]]++;
                int f=mp[nums[j]];
                if(f-1>0){
                    freq[f-1]--;
                    if(freq[f-1]==0){
                        freq.erase(f-1);
                    }
                }
                freq[f]++;
                if(mp.size()==1) ans=max(ans,j-i+1);
                else if(freq.size()==2){
                    auto it=freq.begin();
                    int val=it->first;
                    it++;
                    int val2=it->first;
                    if(val*2==val2) ans=max(ans,j-i+1);
                }


               
                

            }
        }
        return ans;
    }
};