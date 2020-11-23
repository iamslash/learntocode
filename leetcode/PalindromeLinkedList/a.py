# -*- coding: utf-8 -*-

class ListNode:
    def __init__(self, x, y=None):
        self.val = x
        self.next = y

# r           
#         s
#         f
# 1 2 3 2 1
# T: O(N), S: O(1)   
# 136.ms 18.23%
class Solution:
    def isPalindrome(self, head):
        """
        :type head: ListNode
        :rtype: bool
        """
        rev = None
        slow = fast = head
        while fast and fast.next:
            fast = fast.next.next
            rev, rev.next, slow = slow, rev, slow.next
        if fast:
            slow = slow.next
        while rev and rev.val == slow.val:
            slow = slow.next
            rev = rev.next        
        return not rev
    
if __name__ == "__main__":
    # h = ListNode(1, ListNode(2))
    h = ListNode(1, ListNode(2, ListNode(1)))
    sln = Solution()
    print(sln.isPalindrome(h))
