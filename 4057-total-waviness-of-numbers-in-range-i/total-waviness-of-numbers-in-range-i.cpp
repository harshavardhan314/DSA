int find_waviness(int i){

    string s=to_string(i);
    int n=s.size();
    int ans=0;
    for(int i=1;i<n-1;i++){
        int pre=s[i-1]-'0';
        int after=s[i+1]-'0';
        int curr=s[i]-'0';
        if(curr>pre && curr>after) ans++;
        if(curr<pre && curr<after)ans++;
    }
    return ans;
}

class Solution {
public:
    int totalWaviness(int num1, int num2) {

        int ans=0;
        for(int i=num1;i<=num2;i++){
            ans+=find_waviness(i);
        }
        return ans;
        
    }
};