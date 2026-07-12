#pylint: skip-file

class BankAccount:
    def __init__(self, holder) -> None:
        self.holder = holder
        self.balance = 0
    
    def deposit(self, amount):
        self.balance += amount
    
    def withdraw(self, amount):
        if amount >= self.balance:
            raise ValueError("Insufficient Funds")
        self.balance -= amount
    
    def get_balance(self):
        return self.balance

    