# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        def dfs(root):
            if not root: return []
            return dfs(root.right) + [root.val] + dfs(root.left)

        el1, el2, res = dfs(root1), dfs(root2), []       
        while el1 and el2:                
            res.append(el1.pop() if el1[-1] < el2[-1] else el2.pop())

        return res + list(reversed(el1 or el2))
        
        