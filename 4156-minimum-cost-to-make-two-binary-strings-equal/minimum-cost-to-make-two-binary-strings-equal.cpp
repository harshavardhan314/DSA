class Solution {
public:
    long long minimumCost(string s, string t, int flip, int swap, int cross) {
        int n = s.size();
        long long ans = 0,type_1=0,type_2=0;
        for (int i = 0; i < n; i++) {
            if(s[i]=='0' && t[i]=='1')
            type_1++;
            else if(s[i]=='1' && t[i]=='0')
            type_2++;
        }
        long long mini=min(type_1,type_2);
        long long maxii=max(type_1,type_2);
        ans+=min(mini*1LL*swap,mini*2LL*flip);
        maxii-=mini;
        ans+=min((cross+swap)*(maxii/2) , flip*(maxii/2)*2);
        if(maxii%2)
        ans+=flip;
       

        return ans;
    }
};
