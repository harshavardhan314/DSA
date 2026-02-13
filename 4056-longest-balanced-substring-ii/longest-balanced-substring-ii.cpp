class Solution {
public:
    int longestBalanced(string s) {
        map<pair<int,int>,int>mp;
        int v1=0;
        int v2=0;
        int n=s.size();
        int ans=1;
        mp[{0,0}]=-1;
        for(int i=0;i<n;i++){
            if(s[i]=='a')v1++;
            if(s[i]=='c')v2++;
            if(s[i]=='b'){
                v1--;
                v2--;
            }
            if(!mp.count({v1,v2}))mp[{v1,v2}]=i;
            
            ans=max(ans,i-mp[{v1,v2}]);

        }

        vector<string>comb{"ab","bc","ac"};
        for(auto it:comb){
            char x=it[0],y=it[1];
            map<int,int>m;
            m[0]=-1;
            int val=0;
            for(int i=0;i<n;i++){
                if(s[i]==x)val++;
                else if(s[i]==y)val--;
                else{
                val=0;
                m.clear();}
                if(!m.count(val))m[val]=i;
                ans=max(ans,i-m[val]);
            }
        }

        int adj=1;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1])adj++;
            else adj=1;
            ans=max(ans,adj);

        }
        return ans;
        
    }
};