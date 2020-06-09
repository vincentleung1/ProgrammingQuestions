# https://leetcode.com/problems/invert-binary-tree/

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution(object):
    def invertTree(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        self.swap(root)
        return root
    
    def swap (self, root):
        if not root:
            return
        temp = root.left
        root.left = root.right
        root.right = temp
        self.swap(root.left)
        self.swap(root.right)
