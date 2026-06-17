class Solution {
public:
    char processStr(string s, long long k) {

        long long len=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='*'){
                len= max(0LL,len-1);
            }
            else if(s[i]=='#'){
                len = len*2;
            }
            else if(s[i]=='%'){
                continue;
            }
            else{
                len++;
            }
        }
        if(k>=len)return '.';
        reverse(s.begin(),s.end());
        for(int i=0;i<n;i++){

           
            if(s[i]=='#'){
                len=len/2;
                if(len<=k){
                    k-=len;
                }


            }
            else if(s[i]=='*'){
                len++;
            }
            else if(s[i]=='%'){
                k=len-k-1;
                
            }
            else{
                len--;
                if(len<=k)return s[i];

            }
        }
        return '.';
        
    }
};