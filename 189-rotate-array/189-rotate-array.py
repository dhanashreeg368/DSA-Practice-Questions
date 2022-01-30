class Solution:
    def rotate(self, nums: List[int], k: int) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        """
        This question is solved by taking temp variable. It will store the last element the simply   
        change the positions of elements.
        Traversing from back
        """
        k = k % len(nums)
        if not k:
            return
        nums[:k], nums[k:] = nums[-k:], nums[:-k]
            
            
        