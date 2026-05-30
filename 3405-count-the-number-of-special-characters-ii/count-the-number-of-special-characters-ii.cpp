class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>mp;
        int n=word.size();
        for(int i=0;i<n;i++){
            if(word[i]>='a' && word[i]<='z')
                mp[word[i]]=i;
        }
        int cnt=0;
        set<char>st;
        for(int i=0;i<n;i++){
            if(word[i]>='A' && word[i]<='Z' && st.find(word[i])==st.end() && mp.find(tolower(word[i]))!=mp.end()){
                int last_occ=mp[tolower(word[i])];

                if(last_occ<i)cnt++;
                st.insert(word[i]);
            }
        }
        return cnt;
        
    }
};