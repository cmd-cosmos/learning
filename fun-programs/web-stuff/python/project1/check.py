# pylint : skip-file
# type : ignore

import sys

if hasattr(sys, 'real_prefix') or (hasattr(sys, 'base_prefix') and sys.base_prefix != sys.prefix):
    print("Inside venv")
else:
    print("Not in venv")