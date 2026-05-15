# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        num1 = ""
        nums_from_l1 = l1
        while nums_from_l1:
            num1 += str(nums_from_l1.val)
            nums_from_l1 = nums_from_l1.next
        num1 = int(num1[::-1])

        num2 = ""
        nums_from_l2 = l2
        while nums_from_l2:
            num2 += str(nums_from_l2.val)
            nums_from_l2 = nums_from_l2.next
        num2 = int(num2[::-1])

        ans_ll = ListNode(0)
        curr = ans_ll
        
        ans_str = str(num1 + num2)
        for s in ans_str[::-1]:
            curr.next = ListNode(int(s))
            curr = curr.next
        
        return ans_ll.next
            