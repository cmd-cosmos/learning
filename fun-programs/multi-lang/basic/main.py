#pylint: skip-file
#type: ignore

import subprocess

process = subprocess.run(["multiply.exe"], input="100 2000", text=True, capture_output=True)

res = int(process.stdout.strip())
print("C++ routine returned: ", res)

print("\nC++ debug output:")
print(process.stderr)