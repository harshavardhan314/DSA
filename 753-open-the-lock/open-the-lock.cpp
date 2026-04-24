class Solution {
public:
    int openLock(vector<string>& d, string target) {

        string s="0000";
        set<string>st;
        for(auto it:d){
            st.insert(it);
        }
        if(st.find(s)!=st.end())return -1;
       queue<pair<int,string>>q;
        q.push({0,s});
        set<string>vis;
        vis.insert(s);

        
        while(!q.empty()){
            int sz=q.size();
            
                auto[steps,curr]=q.front();
                if(curr==target){
                    return steps;
                }
                q.pop();

            for(int i=0;i<4;i++){
                string temp=curr;
                int new_d1=(temp[i]-'0'+1)%10;
                int new_d2=(temp[i]-'0'-1+10)%10;
                temp[i]=new_d1+'0';
                if(st.find(temp)==st.end() && vis.find(temp)==vis.end()){
                    vis.insert(temp);
                    q.push({steps+1,temp});
                }
                temp[i]=new_d2+'0';
                if(st.find(temp)==st.end() && vis.find(temp)==vis.end()){
                    vis.insert(temp);
                    q.push({steps+1,temp});
                }
            }


                

         
                
            
        }
        return -1;

        
    }
};