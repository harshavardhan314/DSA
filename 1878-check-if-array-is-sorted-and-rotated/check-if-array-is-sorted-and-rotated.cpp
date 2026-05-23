class Solution {
public:
    bool check(vector<int>& arr) {


        int found=false;
        int n=arr.size();

        for(int i=0;i<n;i++){

            int next_idx=(i+1)%n;
            if(arr[i]>arr[next_idx]){
                if(found)return false;
                found = true;
            }
        }
        return true;
        
    }
};