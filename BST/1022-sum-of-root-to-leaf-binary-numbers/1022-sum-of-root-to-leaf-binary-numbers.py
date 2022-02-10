# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def sumRootToLeaf(self, root: Optional[TreeNode]) -> int:
        stack=[(root,0)]
        ans=[]
        bi_str=[]
        while stack:
            node,level=stack.pop()
            s_len=len(bi_str)
            if s_len-1<level:
                bi_str.append(str(node.val))
            else:
                bi_str[level]=str(node.val)
                del bi_str[level+1:]
            if (not node.left) and (not node.right):
                ans.append(int(''.join(bi_str),2))
            if node.right:
                stack.append((node.right,level+1))
            if node.left:
                stack.append((node.left,level+1))
        return sum(ans)
        