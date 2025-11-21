class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>letters;
        int ans=0;
        for(auto it:s)
        {
            letters.insert(it);
        }
        for(auto ch:letters)
        {
            int first=-1;
            int last=0;
            for(int i=0;i<s.size();i++)
            {
                if(s[i]==ch)
                {
                    if(first==-1)first=i;
                    last=i;
                }
            }
            unordered_set<char>st;
            for(int j=first+1;j<last;j++)
            {
                st.insert(s[j]);
            }
            ans+=st.size();
        }
        return ans;
       
    }
};