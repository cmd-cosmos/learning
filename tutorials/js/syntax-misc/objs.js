const user = {
    name : "batman",
    greet() {
        console.log(this.name + " is here");
    }
};

const greetMe = user.greet;
greetMe(); // undefined

const workingGreet = user.greet.bind(user);
workingGreet();

// static methods 

class Utils {
    static add(a, b) {
        return a + b;
    }
}

console.log(Utils.add(1,2));