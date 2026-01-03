class Animal {
    speak() {
        console.log("animal speaks");
    }
}

class Dog extends Animal {
    speak() {
        console.log("dog speaks");
    }
}

const dog = new Dog();
dog.speak();