#pylint: skip-file
#type:ignore

from rich.progress import Progress
import time

with Progress() as progress:
    task = progress.add_task("[bold green]Loading...", total=100)

    for _ in range(100):
        time.sleep(0.1)
        progress.update(task, advance=1)

