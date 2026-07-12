#pylint: skip-file

import pytest
from src.bank import BankAccount

def test_account_creation():
    account = BankAccount("Batman")
    
    assert account.holder == "Batman"
    assert account.balance == 0
    
def test_deposit_changes_balance():
    account = BankAccount("Batman")
    account.deposit(1000)
    
    assert account.balance == 1000

def test_multiple_deposits():
    account = BankAccount("Batman")
    account.deposit(100)
    account.deposit(200)
    
    assert account.balance == 300
    
def test_withdraw_changes_balance():
    account = BankAccount("Batman")
    account.deposit(1000)
    account.withdraw(500)
    
    assert account.balance == 500

def test_withdraw_more_than_balance():
    account = BankAccount("Batman")
    account.deposit(1000)
    
    with pytest.raises(ValueError):
        account.withdraw(2000)    

    