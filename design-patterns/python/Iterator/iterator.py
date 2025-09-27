### iterator pattern - behavioral pattern

class ListNode:
    def __init__(self, val):
        self.val  = val
        self.next = None

class LinkedList:
    def __init__(self, head):
        self.head = head
        self.cur  = None

    def __iter__(self):
        self.cur = self.head
        return self
    
    def __next__(self):
        if self.cur:
            val = self.cur.val
            self.cur = self.cur.next
            return val
        else:
            raise StopIteration
        
head           = ListNode(1)
head.next      = ListNode(2)
head.next.next = ListNode(2)
ll             = LinkedList(head=head)

for val in ll:
    print(val)