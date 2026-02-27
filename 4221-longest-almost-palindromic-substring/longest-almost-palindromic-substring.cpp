int get_len(int l,int r,string &s){
    int n=s.size();
    int ans=1;
    while(l>=0 && r<n && s[l]==s[r]){
            l--;
            r++;
    }
    ans=max(ans,r-l-1);
    int tl=l-1;
    int tr=r;
    while(tl>=0 && tr<n &&  s[tl]==s[tr]){
        tl--;
        tr++;
    }
    ans=max(ans,tr-tl-1);
    tl=l;
    tr=r+1;
    while(tl>=0 && tr<n && s[tl]==s[tr]){
        tl--;
        tr++;
    }
    ans=max(ans,tr-tl-1);
    return ans;
}
class Solution {
public:
    int almostPalindromic(string s) {
        int n=s.size();
        int ans=1;
        int even=1;
        int odd=1;
        for(int i=0;i<n;i++){
            odd=get_len(i,i,s);
            if(i>0){
                even=get_len(i-1,i,s);
            }
            ans=max({ans,even,odd});
        }
        return min(n,ans);
    }
};