#pylint: skip-file
#type: ignore

from rich import print
from rich.table import Table

table = Table(title="Mult Table")

table.add_column("a", justify="right")
table.add_column("b", justify="right")
table.add_column("result", justify="right")

table.add_row("4", "5", "20")

print(table)
