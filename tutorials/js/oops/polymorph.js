class Bird {
    fly() {
        console.log("bird flies");
    }
}

class Penguin extends Bird {
    fly() {
        console.log("penguins do not fly");
    }
}

const birds = [new Bird(), new Penguin()];

birds.forEach(b => b.fly());