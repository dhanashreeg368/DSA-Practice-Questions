# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:

    def __init__(self, head: Optional[ListNode]):
        self.head=head
        
    def getRandom(self) -> int:
        curr = self.head
        i = 0
        
        while curr:
            i += 1
            if random.random() < 1 / i:
                random_val = curr.val
            
            curr = curr.next
            
        return random_val
        


# Your Solution object will be instantiated and called as such:
# obj = Solution(head)
# param_1 = obj.getRandom()