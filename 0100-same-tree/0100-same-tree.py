# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        if not p and not q:					#(1)
            return True
        if p and q and p.val == q.val:		#(2)
            return self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right)
        else:								#(3)
            return False
        