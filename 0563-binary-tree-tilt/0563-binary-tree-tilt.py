# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def findTilt(self, root: Optional[TreeNode]) -> int:
        self.total_tilt = 0
        
        def calculate_subtree_sum(node: Optional[TreeNode]) -> int:
            if not node:
                return 0
            
            # Recursively find the sum of the left and right subtrees
            left_sum = calculate_subtree_sum(node.left)
            right_sum = calculate_subtree_sum(node.right)
            
            # The tilt of the current node is the absolute difference between subtree sums
            node_tilt = abs(left_sum - right_sum)
            self.total_tilt += node_tilt
            
            # Return the total sum of values in the subtree rooted at this node
            return node.val + left_sum + right_sum
        
        calculate_subtree_sum(root)
        return self.total_tilt
