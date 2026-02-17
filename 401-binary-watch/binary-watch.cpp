class Solution {
public:
    vector<string> readBinaryWatch(int on) {

        vector<string>ans;
            for(int k=0;k<12;k++){
                int bits=__builtin_popcount(k);
                        for(int m=0;m<60;m++){
                            int val=__builtin_popcount(m);
                            if(val+bits==on){
                                string s1=to_string(k);
                                string s2=to_string(m);
                               
                                if(s2.size()==1){
                                    s2='0'+s2;
                                }
                                string res=s1+":"+s2;
                                ans.push_back(res);
                            }
                        }
                        
                    
                
            }
        
        return ans;
    }
};