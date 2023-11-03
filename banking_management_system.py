class Bank:
    def __init__(self):
        self.accounts = {}
        self.total_balance = 0
        self.total_loan_amount = 0
        self.loan_feature = True

    def create_account(self, name, initial_deposit):
        if initial_deposit < 0:
            return "Invalid deposit amount"
        elif name in self.accounts:
            return "Account already exists"
        else:
            self.accounts[name] = initial_deposit
            self.total_balance += initial_deposit
            return "Account created successfully"

    def deposit(self, name, amount):
        if amount < 0:
            return "Invalid deposit amount"
        elif name not in self.accounts:
            return "Account does not exist"
        else:
            self.accounts[name] += amount
            self.total_balance += amount
            return "Amount deposited successfully"

    def withdraw(self, name, amount):
        if name not in self.accounts:
            return "Account does not exist"
        elif amount < 0:
            return "Invalid withdrawal amount"
        elif self.accounts[name] < amount:
            return "Insufficient balance"
        else:
            self.accounts[name] -= amount
            self.total_balance -= amount
            return "Amount withdrawn successfully"

    def transfer(self, sender_name, receiver_name, amount):
        if sender_name not in self.accounts:
            return "Sender account does not exist"
        elif receiver_name not in self.accounts:
            return "Receiver account does not exist"
        elif amount < 0:
            return "Invalid transfer amount"
        elif self.accounts[sender_name] < amount:
            return "Insufficient balance"
        else:
            self.accounts[sender_name] -= amount
            self.accounts[receiver_name] += amount
            return "Amount transferred successfully"

    def check_balance(self, name):
        if name not in self.accounts:
            return "Account does not exist"
        else:
            return f"Available balance: {self.accounts[name]}"

    def take_loan(self, name):
        if name not in self.accounts:
            return "Account does not exist"
        elif not self.loan_feature:
            return "Loan feature is currently off"
        elif self.accounts[name] * 2 <= self.total_loan_amount:
            return "Loan limit exceeded"
        else:
            self.accounts[name] += self.accounts[name]
            self.total_loan_amount += self.accounts[name]
            return "Loan taken successfully"


class Admin:
    def __init__(self, bank):
        self.bank = bank

    def check_total_balance(self):
        return f"Total available balance: {self.bank.total_balance}"

    def check_total_loan_amount(self):
        return f"Total loan amount: {self.bank.total_loan_amount}"

    def toggle_loan_feature(self):
        self.bank.loan_feature = not self.bank.loan_feature
        return f"Loan feature is now {'on' if self.bank.loan_feature else 'off'}"

if __init__ == "__main"
