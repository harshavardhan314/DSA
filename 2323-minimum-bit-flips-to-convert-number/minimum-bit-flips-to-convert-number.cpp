

class Solution {
public:
    int minBitFlips(int start, int goal) {
        
        int cnt=0;
        for(int i=0;i<32;i++){
            int have1=(1LL<<i)&start;
            int have2=(1LL<<i)&goal;
            if(have1!=have2){
                cnt++;
            }
        }
        return cnt;
        
    }
};