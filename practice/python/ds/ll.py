### singly linked list

class Node:
    def __init__(self, value) -> None:
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
    
node = Node(5)
print(repr(node))
print(str(node))
# print(node) ---> uses the str method as __str__ holds a higher priority
