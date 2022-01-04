class Solution:
    import math
    def bitwiseComplement(self, n: int) -> int:
        mask = 1
        while n > mask:
            mask = mask*2+1
        return mask-n
        