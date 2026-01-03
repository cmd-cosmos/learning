class Engine {
    start() {
        console.log("engine started");
    }
}

class Car {
    constructor() {
        this.engine = new Engine();
    }

    drive() {
        this.engine.start();
        console.log("car starts to move");
    }
}

const car = new Car();
car.drive();