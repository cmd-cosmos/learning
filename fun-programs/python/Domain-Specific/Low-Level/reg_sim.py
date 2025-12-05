#pylint: skip-file
#type: ignore

# basic bitwise register simulator

class Register8Bit:
    def __init__(self) -> None:
        self.value = 0
    
    def write(self, val) -> None:
        # and with 0xFF to ensure val fits in 8 bits
        self.value = val & 0xFF # (1111 1111)
    
    def set_bit(self, bit):
        self.value = self.value | (1 << bit)
    
    def clear_bit(self, bit):
        self.value = self.value & ~(1 << bit)

    def read_bit(self, bit):
        return (self.value >> bit) & 1
    
    def __str__(self) -> str:
        bits = format(self.value, "08b")
        return "0b" + bits[:4] + " " + bits[4:]
    
r = Register8Bit()
r.write(0b00010010)
#   0001 0010
# & 1111 1111
# --------------
#   0001 0010 <---- written --> 18
r.set_bit(0)
# 1 << 0 ===> 0000 0001 << 0 ===> 0000 0001
#  0001 0010
#| 0000 0001
# ----------
#  0001 0011  <---- 19  
r.clear_bit(4)
# ~(1 << 4) = ~(0000 0001 << 4) = ~(0001 0000) = 1110 1111
#   0001 0011
# & 1110 1111
# ------------
#   0000 0011 <---- 3
print(r) # 3 ---> 0000 0011
