# pylint: skip-file

import pytest
from src.calc import add, sub, mult, divide

def test_add():
    assert add(2, 3) == 5
    
def test_sub():
    assert sub(5, 2) == 3

def test_mult():
    assert mult(4, 3) == 12
    
def test_divide():
    assert divide(10, 2) == 5

def test_divide_by_zero():
    with pytest.raises(ZeroDivisionError):
        divide(10, 0)
        
        