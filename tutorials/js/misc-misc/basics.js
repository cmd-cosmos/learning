let score = 100;

console.log(`score = ${score}`)

let user = {
    name : "batman",
    age  : 22,
    isInGotham : true
};

console.log(user.name)
console.log(user.age)
console.log(user.isInGotham)

let nums = [1,2,3,4,5]

for (let num of nums){
    console.log(num);
}

// arrow functions
const mult = (a, b) => a*b;
console.log(mult(3,4));