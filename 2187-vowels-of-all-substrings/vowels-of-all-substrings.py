class Solution:
    def countVowels(self, word: str) -> int:
        want="aeiou"
        ans=0
        n=len(word)

        for idx,val in enumerate(word):
            if val in want:
                right=n-idx
                left=idx+1
                ans+=left*right

        return ans       