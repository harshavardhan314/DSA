class Solution {
public:
    vector<string> generateValidStrings(int n, int k) {

        long long  val=1LL<<n;
        vector<string>ans;
        set<string>st;
        for(int i=0;i<=val;i++){
            string s="";
            int cnt=0;
            for(int j=0;j<n;j++){

                if(cnt>k)break;
                if(i&(1LL<<j)){
                    if(s.size()>0 && s.back()=='1')break;
                    s.push_back('1');
                    cnt+=j;
                }
                else{
                    s.push_back('0');
                }
            }
            if(s.size()==n && cnt<=k && st.find(s)==st.end()){
            ans.push_back(s);
            st.insert(s);
            }
        }
        return ans;

        
    }
};