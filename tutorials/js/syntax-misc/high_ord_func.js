function withLogger(fn) {
    return function (...args) {
        console.log("calling inp func with: ", args);
        const res = fn(...args);
        console.log("result: ", res);
        return res
      };
}

const add = (a, b) => a + b;
const loggedAdd = withLogger(add);

loggedAdd(5, 6);
