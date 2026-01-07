class Solution:
    def sumAndMultiply(self, s: str, q: List[List[int]]) -> List[int]:
        f=defaultdict(int)
        temp=0
        n=len(s)
        pre_sum=[0]*(n+1)
        pre_digit=[0]*(n+1)
        non_zeros=[0]*(n+1)
        res=[]
        c=0
        mod=int(1e9)+7
        for i,val in enumerate(s):
            pre_sum[i+1]=pre_sum[i]+int(val)
            if val!='0':
                c+=1
                pre_digit[i+1]=pre_digit[i]*10+int(val)
            else:
                pre_digit[i+1]=pre_digit[i]
            pre_digit[i+1] = pre_digit[i+1]%mod
            non_zeros[i+1]=c
        pow_10=[0]*(n+1)
        pow_10[1]=10
        for i in range(1,n):
            pow_10[i+1]=(pow_10[i] %mod * 10 %mod)%mod

        for i in q:
            l=i[0]
            r=i[1]
            sum_till=pre_sum[r+1]-pre_sum[l]
            right=pre_digit[r+1]
            left=pre_digit[l]
            if right==left:
                res.append(0)
                continue
            length=non_zeros[r+1]-non_zeros[l]
            left=left*pow_10[length]
            left=left%mod
            ans=(right-left)*sum_till
            res.append(ans%mod)
        return res
        