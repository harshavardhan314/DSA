class Solution:
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        n=len(s)
        prefix_digit=[0]*(n+1)
        prefix_sum=[0]*(n+1)
        digit_len=[0]*(n+1)
        tens_pow=[1]*(n+1)
        mul=1
        mod=int(1e9+7)
        for i in range(1,n+1):
            val=int(s[i-1])
            if val!=0:
                prefix_sum[i]=(prefix_sum[i-1]+val)%mod
                prefix_digit[i]=(prefix_digit[i-1]*10+val)%mod
                digit_len[i]=digit_len[i-1]+1
            else:
                digit_len[i]=digit_len[i-1]
                prefix_sum[i]=prefix_sum[i-1]
                prefix_digit[i]=prefix_digit[i-1]
            
            tens_pow[i]=(tens_pow[i-1]*10)%mod
        
        ans=[]
        
        for i in queries:
            l=i[0]
            r=i[1]

            sum_till_now=prefix_sum[r+1]-prefix_sum[l]
            right=prefix_digit[r+1]
            left=prefix_digit[l]
            len_rem=digit_len[r+1]-digit_len[l]
            left=left*tens_pow[len_rem]
            res=(right-left)%mod
            res=(res*sum_till_now)%mod
            ans.append(res)
        
        return ans

        


        