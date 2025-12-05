#pylint: skip-file
#type: ignore

pc  = 0
acc = 0

prog = [
    ("LOAD",5),
    ("ADD" , 3),
    ("MUL" , 2),
    ("HALT",)
]

while True:
    instruction = prog[pc]
    op = instruction[0]

    if op == "LOAD":
        acc = instruction[1]
    elif op == "ADD":
        acc += instruction[1]
    elif op == "MUL":
        acc *= instruction[1]
    elif op == "HALT":
        break

    pc += 1

print(f"ACC = {acc}") 
