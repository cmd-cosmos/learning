#pylint: skip-file
#type: ignore

from rich.console import Console
from rich.status import Status
import time

console = Console()

steps = [
    "Loading flight configuration parameters",
    "Establishing ground computer to flight computer handover",
    "Initializing guidance, navigation, and control (GNC) systems",
    "Entering terminal count and autonomous launch sequence"
]


with console.status("[bold green]Handover Sequence...[/bold green]") as status:
    for step in steps:
        status.update(f"[bold cyan]{step}[/bold cyan]")
        time.sleep(2)

console.print("[bold green] Go for Terminal Count...[/bold green]")
