class Solution {
public:
    long long countDistinct(long long n) {
        vector<long long >pow(16,1);
        for(int i=1;i<16;i++)
        {
            pow[i]=pow[i-1]*9;
        }
        string s=to_string(n);
        long long ans=0;
        for(int i=1;i<s.size();i++)
        {
            ans+=pow[i];
        }
        int m=s.size();
        int i=0;
        for(i=0;i<s.size();i++)
        {
            if(s[i]=='0') break;
            for(int j=1;j<s[i]-'0';j++)
            {
                ans+=pow[m-i-1];
            }
        }
        return ans+(i>=m);
        
    }
};