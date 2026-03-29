class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& v) {
        set<string>st;
        for(auto it:v){
            st.insert(it);
        }

        int n=v.size();
        queue<string>q;
        q.push(bw);
        int cnt=1;
        while(!q.empty()){

            int sz=q.size();

            for(int i=0;i<sz;i++){

                string s=q.front();
                q.pop();
                if(s==ew)return cnt;

                for(int j=0;j<s.size();j++){

                    char oc=s[j];

                    for(char ch='a';ch<='z';ch++){

                        if(ch==oc)continue;
                        s[j]=ch;
                        if(st.find(s)!=st.end()){
                            q.push(s);
                            st.erase(st.find(s));
                        }
                    }
                    s[j]=oc;
                }
            }
            cnt++;
        }
        return 0;
        
    }
};