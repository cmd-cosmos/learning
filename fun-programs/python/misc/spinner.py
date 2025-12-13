#pylint: skip-file
#type: ignore

from rich.console import Console
from rich.status import Status
import time

console = Console()

steps = [
    "[bold green]Initializing System Checks...[/bold green]",
    "[bold green]Pinging sub systems...[/bold green]",
    "[bold green]Fetching health parameters...[/bold green]",
    "[bold green]System checks complete: NOMINAL[/bold green]"
]

with console.status(steps[0]) as status:
    time.sleep(1)
    status.update(steps[1])
    time.sleep(1)
    status.update(steps[2])
    time.sleep(1)

console.print(steps[3])
