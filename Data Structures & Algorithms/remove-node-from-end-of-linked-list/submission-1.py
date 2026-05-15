# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next

class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        simple_list = []
        curr = head
        while curr:
            simple_list.append(curr.val)
            curr = curr.next

        simple_list.pop(-n)

        if not simple_list:
            return None
        
        curr = head
        for i in range(len(simple_list)):
            curr.val = simple_list[i]
            if i == len(simple_list) - 1:
                curr.next = None
            else:
                curr = curr.next
        
        return head