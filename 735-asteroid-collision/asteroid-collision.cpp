class Solution {
public:
    vector<int> asteroidCollision(vector<int>& arr) {

        int n=arr.size();

        vector<int>ans;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(arr[i]>0){
                st.push(arr[i]);
            }
            else{
                while(!st.empty() && abs(arr[i])>st.top()){
                    st.pop();
                }
                if(!st.empty() && abs(arr[i])==st.top()){st.pop(); continue;}

                if(st.empty())ans.push_back(arr[i]);

            }
        }
        vector<int>temp;
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        for(auto it:temp){
            ans.push_back(it);
        }
        return ans;

        
    }
};