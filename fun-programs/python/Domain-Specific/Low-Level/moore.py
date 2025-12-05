#pylint: skip-file
#type: ignore

state = 0

def next_state(st, inp):
    return (st+inp) & 3

def tick(clk, d):
    global state
    if clk:
        state = d
    return state

inp = 1
for t in range(5):
    ns = next_state(st=state, inp=inp)
    print(f"t: {t}, state: {tick(1, ns)}")
    tick(0, ns) # falling edge
    inp = inp ^ 1
