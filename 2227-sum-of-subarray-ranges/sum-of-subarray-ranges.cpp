long long find_sum_subarray_minimums(vector<int>&nums){
    int n=nums.size();

    vector<int>nse(n,n);
    stack<int>st;
    for(int i=n-1;i>=0;i--){

        while(!st.empty() && nums[i]<nums[st.top()]){
            st.pop();
        }
        nse[i]=st.empty()?n:st.top();
        st.push(i);
    }


    vector<int>pse(n,-1);
    stack<int>st2;
    for(int i=0;i<n;i++){

        while(!st2.empty() && nums[i]<=nums[st2.top()]){
            st2.pop();
        }
        pse[i]=st2.empty()?-1:st2.top();
        st2.push(i);
    }

    long long ans=0;
    for(int i=0;i<n;i++){

        int left=i-pse[i];
        int right=nse[i]-i;
        ans+=1LL*left*right*nums[i];
    }
    return ans;


}

long long find_sum_subarrays_max(vector<int>&nums){

    int n=nums.size();

    vector<int>nge(n,n);

    stack<int>st;
    for(int i=n-1;i>=0;i--){
        while(!st.empty() && nums[i]>nums[st.top()]){
            st.pop();
        }
        nge[i]=st.empty()?n:st.top();
        st.push(i);
    }

    stack<int>st2;

    vector<int>pge(n,-1);
    for(int i=0;i<n;i++){
        while(!st2.empty() && nums[i]>=nums[st2.top()]){
            st2.pop();
        }
        pge[i]=st2.empty()?-1:st2.top();
        st2.push(i);
    }
    long long ans=0;

    for(int i=0;i<n;i++){
        int left=i-pge[i];
        int right=nge[i]-i;
        ans+=1LL*left*right*nums[i];
    }
    return ans;
}

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        return find_sum_subarrays_max(nums)-find_sum_subarray_minimums(nums);
        
    }
};