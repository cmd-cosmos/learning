function createCounter(start = 0) {
    let ct = start;

    return function () {
        ct++;
        return ct;
    };
}

const ctrA = createCounter(5);
console.log(ctrA()); // 6
console.log(ctrA()); // 7 

const ctrB = createCounter();
console.log(ctrB()); // 1
