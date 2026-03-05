int find(string &s,char req){
    int ans=0;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(i%2==0 && s[i]!=req)ans++;
        if(i%2!=0 && s[i]==req)ans++;
    }
    return ans;
}
class Solution {
public:
    int minOperations(string s) {
        
        return min(find(s,'1'),find(s,'0'));
        
    }
};