class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h, string d) {
        vector<pair<int,pair<int,char>>>vp;
        int n=p.size();

        for(int i=0;i<n;i++){
            vp.push_back({p[i],{h[i],d[i]}});
        }
        sort(vp.begin(),vp.end());

        map<int,int>mp; 

        stack<pair<int,pair<int,char>>>st;
        for(int i=0;i<n;i++){
            auto it=vp[i];
            int pos=it.first;
            int curr_heal=it.second.first;
            int ch=it.second.second;
            bool can_i=true;
            while(!st.empty() && (st.top().second.second=='R' && ch=='L')){
                int prev_heal=st.top().second.first;
                int prev_dir=st.top().second.second;
                if(prev_heal==curr_heal){
                    st.pop();
                    can_i=false;
                    break;
                    }
                else if(prev_heal>curr_heal){
                    st.top().second.first--;
                    can_i=false;
                    break;
                }
                else if(curr_heal>prev_heal){st.pop();
                curr_heal--;
                }
            }
            if(can_i)st.push({pos,{curr_heal,ch}});

        }
        vector<int>ans;
        while(!st.empty()){
            auto it=st.top();
            st.pop();
            int pos=it.first;
            int val=it.second.first;
            mp[pos]=val;
        }
       for(int i=0;i<n;i++){
        if(mp[p[i]]>0)
        ans.push_back(mp[p[i]]);
       }
        return ans;
        
    }
};