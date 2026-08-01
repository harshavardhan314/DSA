bool solve(int idx_st,int idx_end,int choice,vector<int>&nums,long long  p1,long long  p2){
    int n=nums.size();

    if(idx_st>idx_end){
       
        return p1>=p2;
    };

    bool ans = (choice % 2 == 0) ? false : true;
 
    if(choice%2==0)
    {
        
        ans = ans or solve(idx_st+1,idx_end,choice+1,nums,p1+nums[idx_st],p2);
        ans =ans  or solve(idx_st,idx_end-1,choice+1,nums,p1+nums[idx_end],p2); 
    }
    else{
    
     ans = ans && solve(idx_st+1,idx_end,choice+1,nums,p1,p2+nums[idx_st]);
     ans =ans  && solve(idx_st,idx_end-1,choice+1,nums,p1,p2+nums[idx_end]); 
    }
    
    
    return ans;
}


class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {

        int n=nums.size();
        return solve(0,n-1,0,nums,0LL,0LL);


        
    }
};