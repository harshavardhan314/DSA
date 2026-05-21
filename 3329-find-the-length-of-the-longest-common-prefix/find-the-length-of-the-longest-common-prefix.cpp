
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        int n=arr1.size();
        int m=arr2.size();
       
        map<string,int>mp;
        for(int i=0;i<m;i++){
            string temp=to_string(arr2[i]);
            string new_str="";
            for(int j=0;j<temp.size();j++){
                new_str.push_back(temp[j]);
                mp[new_str]++;
            }

        }

        int ans=0;
        for(int i=0;i<n;i++){
            string curr=to_string(arr1[i]);
            string new_str="";
            for(int j=0;j<curr.size();j++){
                new_str.push_back(curr[j]);
                int curr_len=new_str.size();
                if(mp.find(new_str)!=mp.end()) ans=max(ans,curr_len);
            }
        }

        return ans;
        
    }
};