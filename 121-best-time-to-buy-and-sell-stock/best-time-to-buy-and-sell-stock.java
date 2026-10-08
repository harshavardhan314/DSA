class Solution {
    public int maxProfit(int[] prices) {

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.length; i++) {

            minPrice = Math.min(minPrice, prices[i]);

            int profit = prices[i] - minPrice;

            maxProfit = Math.max(maxProfit, profit);
        }

        return maxProfit;
    }
}
/************** Brute Force Approach
// class Solution {
//     public int maxProfit(int[] prices) {
        
//         int n=prices.length,i,j,ans=0,max;
//         for(i=0;i<n;i++)
//         {
//             j=i+1;
//             while(j<n)
//             {
//                 max=prices[j]-prices[i];
//                 ans=Math.max(ans,max);
//                 j++;
//             }
//         }
//         return ans;
//     }
// }
*********************/
// class Solution {
//     public int maxProfit(int[] prices) {

//         int n = prices.length;
//         int ans = 0;

//         for (int i = 0; i < n; i++) {

//             for (int j = i + 1; j < n; j++) {

//                 int profit = prices[j] - prices[i];

//                 ans = Math.max(ans, profit);
//             }
//         }

//         return ans;
//     }
// }
