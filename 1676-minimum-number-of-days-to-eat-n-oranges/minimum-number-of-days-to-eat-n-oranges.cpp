unordered_map<int,int>dp;
int solve(int n){
    if(n<=1) return n;
    if(dp.count(n))return dp[n];
    int op1 =n%2 + 1+solve(n/2);
    int op2 =n%3+ 1+solve((n/3));
    return dp[n]=min(op1,op2);
}
class Solution {
public:
    int minDays(int n) {
        return solve(n);
        
    }
};