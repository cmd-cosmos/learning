#pylint: skip-file
#type: ignore

# simulating a level-sensitive D-latch that holds a val passed when clock is high
# if bit == 1 at clock == 1 --> bit held till bit set to 0 on another high edge

D = 0
bit = 0

def tick(clk, bit_val):
    global bit
    if clk:
        bit = bit_val
    return bit

print(f"CLOCK STATE: 1 | SET BIT: {tick(1, 1)}")
print(f"CLOCK STATE: 0 | BIT STATE: {tick(0, 1)}")
print(f"CLOCK STATE: 1 | BIT STATE: {tick(1, 1)}")
print(f"CLOCK STATE: 0 | BIT STATE: {tick(0, 1)}")
print(f"CLOCK STATE: 1 | RESET BIT: {tick(1, 0)}")
print(f"CLOCK STATE: 0 | BIT STATE: {tick(0, 1)}")

