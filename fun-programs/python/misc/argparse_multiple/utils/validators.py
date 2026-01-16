#pylint: skip-file

import argparse
import os

def existing_file(path):
    if not os.path.isfile(path):
        raise argparse.ArgumentTypeError(f"File does not exist: {path}")
    return path