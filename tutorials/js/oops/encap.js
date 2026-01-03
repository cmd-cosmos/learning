class Account {
    #balance = 0;
    pubBalance = 0;

    deposit(amt) {
        this.#balance += amt;
    }

    display() {
        return this.#balance;
    }
}

const acc = new Account();
acc.deposit(100);
console.log(acc.display());
// console.log(acc.#balance) // error
console.log(acc.pubBalance) // we can access this public balance

