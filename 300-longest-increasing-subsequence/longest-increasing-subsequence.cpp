int LIS(vector<int>&nums){
    int n=nums.size();
    
    vector<int>new_seq;
    new_seq.push_back(nums[0]);
    for(int i=1;i<n;i++){
        int  idx=lower_bound(new_seq.begin(),new_seq.end(),nums[i])-new_seq.begin();
        if(idx<new_seq.size()){
            new_seq[idx]=nums[i];
        }
        else{
            new_seq.push_back(nums[i]);
        }
    }
    return new_seq.size();
}

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        return LIS(nums);
        
    }
};