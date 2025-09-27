### behavioral pattern

from abc import ABC, abstractmethod

class FilterStrategy(ABC):
    @abstractmethod
    def removeVal(self,val):
        pass

class RemoveNegativeStrategy(FilterStrategy):
    def removeVal(self, val):
        return val < 0
    
class RemoveOddStrategy(FilterStrategy):
    def removeVal(self, val):
        return abs(val) % 2
    
class Values:
    def __init__(self, vals) -> None:
        self.vals = vals

    def filter(self, strategy):
        res = []
        for num in self.vals:
            if not strategy.removeVal(num):
                res.append(num)
        return res

vals = Values([3, -7, 6, 10, -87, 109])
positives = vals.filter(RemoveNegativeStrategy())
print(positives)

evens = vals.filter(RemoveOddStrategy())
print(evens)