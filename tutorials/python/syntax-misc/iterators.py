# pylint: skip-file

# iterator --> obj represents a data stream
# 2 dunder methods implemented --> iter and next

class CounterUP:
    def __init__(self, bound) -> None:
        self.bound = bound
        self.curr = 0

    def __iter__(self):
        return self
    
    def __next__(self):
        if self.curr >= self.bound:
            raise StopIteration
        self.curr += 1
        return self.curr
    
counter = CounterUP(5) # init and iter called, obj bound set to 5 and curr set to 0 

for i in counter:
    # this for loop calls iter once and calls next in the remaining iterations
    print(i)



