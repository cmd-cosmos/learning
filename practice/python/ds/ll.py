### singly linked list
### ref: https://realpython.com/linked-lists-python/

class Node:
    def __init__(self, value):
        self.value = value
        self.next  = None

    def __repr__(self):
        """
        returns a more detailed version(programmer friendly) of object information
        """
        print("repr method called:")
        return f"Node(Value: {self.value})"
    
    def __str__(self) -> str:
        """return a user friendly version of the node object"""
        return f"Object: ({self.value})"
    
class LinkedList:
    def __init__(self):
        self.head = None

    def __repr__(self) -> str:
        node  = self.head
        nodes = []
        while node is not None:
            nodes.append(node.value)
            node = node.next
        nodes.append("None")
        return " -> ".join(nodes)
    
ll = LinkedList()
print("Initialized a linked list")
print("LL contents: ", ll)

head_node = Node("a")
ll.head = head_node # type: ignore
node1 = Node("b")
head_node.next = node1 # type: ignore
node2 = Node("c")
node1.next = node2 # type: ignore
node3 = Node("d")
node2.next = node3 # type: ignore

print(ll)
    
# node = Node(5)
# print(repr(node))
# print(str(node))
# print(node) ---> uses the str method as __str__ holds a higher priority
