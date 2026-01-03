class Student {
    constructor(name) {
        this._name = name;
    }

    get name() {
        return this._name;
    }

    set name(newName) {
        this._name = newName;
    }
}

const s = new Student("Joker");
s.name = "Batman";
console.log(s.name);