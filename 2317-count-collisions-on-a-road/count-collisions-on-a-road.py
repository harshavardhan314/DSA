class Solution:
    def countCollisions(self, s: str) -> int:
        final=s.lstrip('L').rstrip('R')
        return len(final)-final.count('S')

        