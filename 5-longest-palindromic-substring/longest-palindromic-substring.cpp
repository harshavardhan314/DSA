pair<int,int>expand(int l,int r,string&s){

    while(l>=0 && r<s.size() && s[l]==s[r]){
        r++;
        l--;
    }
    return {l+1,r-1};
}



class Solution {
public:
    string longestPalindrome(string s) {

        int ans=0;
        int n=s.size();
        int st=-1;
        int end=-1;
        string res="";
        for(int i=0;i<n;i++){

            
            auto[l2,r2]=expand(i,i,s);
            if(i>0){
            auto[l1,r1]=expand(i-1,i,s);
            if(r1-l1+1>ans){
                ans=r1-l1+1;
                st=l1;
                end=r1;
            }
            }
            if(r2-l2+1>ans){
                ans=r2-l2+1;
                st=l2;
                end=r2;
            }
        }
        for(int i=st;i<=end;i++){
            res+=s[i];
        }
     
       
        return res;
    }
};