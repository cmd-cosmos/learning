# type : ignore
# pylint : skip-file
import sys

if hasattr(sys, 'real_prefix') or (hasattr(sys, 'base_prefix') and sys.base_prefix != sys.prefix):
    print("Inside venv")
else:
    print("Not in venv")