# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:

        m = 0
        current_head = head
        while current_head is not None:
            current_head = current_head.next
            m += 1

        k = m - n + 1

        # print(f"m: {m} k: {k}")

        i = 1
        k_m1 = None
        k_p1 = None
        current_head = head

        while current_head is not None:
            if i == k-1:
                k_m1 = current_head
            if i == k+1:
                k_p1 = current_head

            current_head = current_head.next
            i += 1

        if k_p1 is None and k_m1 is None:
            return None

        if k_m1 is not None and k_p1 is not None:
            k_m1.next = k_p1
            # print(f"{k_m1.val} {k_p1.val}")
        
        if k_p1 is None and k_m1 is not None:
            k_m1.next = None

        if k_p1 is not None and k_m1 is None:
            head = k_p1

        return head
