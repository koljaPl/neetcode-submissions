class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow = head
        fast = head

        while fast and fast.next:
            slow = slow.next          # двигаем slow на 1 шаг
            fast = fast.next.next     # двигаем fast на 2 шага

            if slow == fast:          # если встретились — есть цикл
                return True

        return False