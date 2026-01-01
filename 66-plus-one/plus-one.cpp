class Solution {
public:
    vector<int> plusOne(vector<int>& d) {
        vector<int>res;
        int n=d.size();
        int carry=1;
        for(int i=n-1;i>=0;i--)
        {
            int curr=d[i]+carry;
            if (i==0)
            {
                if (curr>=10){
                res.push_back(curr%10);
                 res.push_back(curr/10);
                }
                else
                {
                    res.push_back(curr);
                }
            }
            else{
               
                    res.push_back(curr%10);
            }
            carry=curr/10;
        }
        
        reverse(res.begin(),res.end());
        return res;
    }
};