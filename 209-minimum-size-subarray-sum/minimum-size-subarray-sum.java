class Solution {
    public int minSubArrayLen(int target, int[] nums) {
        int n=nums.length;
        int l=0,sum=0,r=0;
        int minLen = Integer.MAX_VALUE;

        for(r=0;r<n;r++)
        {
            sum+=nums[r];
            while(sum>=target)
            {
                minLen=Math.min(minLen,r-l+1);
                sum-=nums[l];
                l++;
            }
        }
        return minLen == Integer.MAX_VALUE ? 0 : minLen;













        // for(i=0;i<n;i++)
        // {
        //     while(sum>=target)
        //     {
        //         sum=sum+nums[i];
        //         i++;
        //         count=i+1;
        //     }
        //     res=Math.min(res,count);
        //     if(sum>target)
        //     {
        //         flag=sum-nums[i];
        //         if(flag>target)
        //         {
        //             flag=flag-num[i+1];
        //         }                      
                
        //     }
        // }



    }
}