#pylint: skip-file
#type: ignore

# basic bitwise register simulator

class Register8Bit:
    def __init__(self) -> None:
        self.value = 0
    
    def write(self, val) -> None:
        self.value = val & 0xFF # (1111 1111)
    
    def set_bit(self, bit):
        self.value = self.value | (1 << bit)
    
    def clear_bit(self, bit):
        self.value = self.value & ~(1 << bit)

    def read_bit(self, bit):
        return (self.value >> bit) & 1
    
r = Register8Bit()

r.write(0b00010010)
r.set_bit(0)
r.clear_bit(4)
print(bin(r.value))
