class Solution:
    def reverseWords(self, s: str) -> str:
        arr=s.split()
        cnt=0
        for i in arr[0]:
            if i=='a' or i=='e' or i=='i' or i=='o' or i=='u':
                cnt+=1
        
        for i in range(1,len(arr)):
            curr_cnt=0
            for j in arr[i]:
                if j=='a' or j=='e' or j=='i' or j=='o' or j=='u':
                    curr_cnt+=1
            if curr_cnt==cnt:
                arr[i]=arr[i][::-1]
        
        ans=' '.join(arr)
        return ans

        