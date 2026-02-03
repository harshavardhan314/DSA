class Solution {
public:
    vector<int>ans;
    int min_diff=INT_MAX;
    
    
    vector<int> minDifference(int n, int k) {

        vector<int>curr;
        backtrack(n,k,curr,1);
        return ans;
    }

    void backtrack(int n,int k,vector<int>&curr,int start){

        if(k==1){
            if(n>=start){
            curr.push_back(n);
            check(curr);
            curr.pop_back();}
            return ;
        }
        for(int i=start;i<=n;i++){
            if(n%i==0){
                curr.push_back(i);
                backtrack(n/i,k-1,curr,i);
                curr.pop_back();
            }
        }
        return ;
    }

    void check(vector<int>&curr){
        int curr_diff=curr.back()-curr.front();
        if(curr_diff<min_diff){
            ans=curr;
            min_diff=curr_diff;
        }
        return ;
    }
};