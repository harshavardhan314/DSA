vector<pair<int,int>>merge(vector<vector<int>>&i){
    vector<pair<int,int>>temp;
    temp.push_back({i[0][0],i[0][1]});
    for(int j=1;j<i.size();j++){

        int st=i[j][0];
        int end=i[j][1];
        if(st<=temp.back().second){
            temp.back().second=max(temp.back().second,end);
        }
        else{
            temp.push_back({st,end});
        }


    }
    return temp;
}

class Solution {
public:
    long long minEnergy(int n, int b, vector<vector<int>>& intervals) {

        sort(intervals.begin(),intervals.end());

        vector<pair<int,int>>interval=merge(intervals);
        long long int want = b/min(n,3);
        if(b%(min(n,3))!=0)want++;
        long long ans=0;
        for(auto [st,end]:interval){
            long long int len=end-st+1;
            ans+=len*want;
        }        
        return ans;
    }
};