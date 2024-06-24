# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        if not preorder or not inorder:
            return None
        
        # Root is the first element of preorder
        root_val = preorder[0]
        root = TreeNode(root_val)
        
        # Find the root in inorder
        root_index = inorder.index(root_val)
        
        # Elements left to the root_index in inorder are part of the left subtree
        left_inorder = inorder[:root_index]
        # Elements right to the root_index in inorder are part of the right subtree
        right_inorder = inorder[root_index + 1:]
        
        # Elements for the left subtree in preorder (skip the root element)
        left_preorder = preorder[1:1 + len(left_inorder)]
        # Elements for the right subtree in preorder
        right_preorder = preorder[1 + len(left_inorder):]
        
        # Recursively build the left and right subtree
        root.left = self.buildTree(left_preorder, left_inorder)
        root.right = self.buildTree(right_preorder, right_inorder)
        
        return root