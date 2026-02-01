class Solution {
public:
        long long nCr(int n, int r) {
            if (r > n) return 0;
            r = min(r, n - r);
            long long ans = 1;
            for (int i = 1; i <= r; i++) {
                ans = ans * (n - r + i) / i;
            }
            return ans;
        }

    long long nthSmallest(long long n, int k) {

        long long ans=0;

        for(int i=50;i>=0;i--){
            
            long long  count=nCr(i,k);
           
            
            if(n>count){
                n-=count;
                k--;
                ans|=(1LL<<i);
            }
            

        }
        return ans;

        
    }
};