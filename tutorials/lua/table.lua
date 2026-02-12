-- tables are objects

person = {
    name = "Batman",
    age = 22
}

print(person.name)

math_ops = {}

math_ops.add = function(a, b)
    return a+b
end

print(math_ops.add(10,20))