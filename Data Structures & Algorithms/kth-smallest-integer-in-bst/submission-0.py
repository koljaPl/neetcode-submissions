# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def kthSmallest(self, root: Optional[TreeNode], k: int) -> int:
        list_of_nums = []

        def get_values(curr):
            if not curr:
                return
            
            list_of_nums.append(curr.val)

            get_values(curr.left)
            get_values(curr.right)
        
        get_values(root)

        return sorted(list_of_nums)[k - 1]