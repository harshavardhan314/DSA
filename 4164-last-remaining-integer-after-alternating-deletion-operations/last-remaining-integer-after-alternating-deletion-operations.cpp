class Solution {
public:
    long long lastInteger(long long n) {
        long long diff=1;
        long long val=1;
        long long len=n;
        long long cnt=0;
        while (n>1){
            if(cnt%2 and n%2==0)
            val+=diff;
            diff=diff*2;
            cnt++;
            long long remove=n/2;
            n=n-remove;

        }
        return val;

        
        
    }
};