#pylint: skip-file
#type: ignore

from rich import print
from rich.table import Table
import argparse

if __name__ == "__main__":
    
    parser = argparse.ArgumentParser()
    parser.add_argument("--val", type=int, required=True, help="Value for mult table")
    args = parser.parse_args()

    inp = args.val
    table = Table(title="Mult Table")

    table.add_column("a", justify="right")
    table.add_column("b", justify="right")
    table.add_column("result", justify="right")

    # inp = int(input("Enter num: "))
    print('\n')

    for i in range(1, 11):
        table.add_row(str(inp), str(i), str(inp * i))

    print(table)
