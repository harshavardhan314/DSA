class Solution:
    def checkDivisibility(self, n: int) -> bool:
        temp=n
        mul,add=1,0
        while temp>0:
            mul=mul*(temp%10)
            temp=temp//10
        temp=n
        while temp>0:
            add=add+temp%10
            temp=temp//10
        
        return n%(add+mul)==0
        