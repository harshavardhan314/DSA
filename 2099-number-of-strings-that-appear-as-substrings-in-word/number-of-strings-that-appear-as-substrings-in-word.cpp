
class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {

        int n=word.size();
      set<string>st;
      for(int i=0;i<n;i++){
        string temp="";
        for(int j=i;j<n;j++){
            temp.push_back(word[j]);
            st.insert(temp);
        }
      }
      int ans=0;
      for(auto it:patterns){
        if(st.find(it)!=st.end())ans++;
      }
      return ans;
    }
};