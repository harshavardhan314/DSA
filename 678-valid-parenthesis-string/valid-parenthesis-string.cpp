class Solution {
public:
    bool checkValidString(string s) {

        stack<pair<char,int>>st;
        stack<int>idx;
        int n=s.size();
        for(int i=0;i<n;i++){

            if(s[i]=='*')idx.push(i);

            else if(s[i]==')'){

                if(st.empty()){
                    if(!idx.empty() && idx.top()<i){
                        idx.pop();
                    }
                    else
                    return false;
                }
                else{
                    st.pop();
                }
            }
            else{
                st.push({s[i],i});
            }

            
        }
        while(!st.empty() && !idx.empty()){
            if(idx.top()>st.top().second){
                st.pop();
                idx.pop();
            }
            else break;
        }
        if(!st.empty())return false;
        return true;
        
    }
};