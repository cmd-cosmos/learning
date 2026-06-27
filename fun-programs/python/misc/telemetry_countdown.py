#pylint: skip-file
#type: ignore
import time
import random
import logging
from rich.progress import Progress
from rich.console import Console

logging.basicConfig(
    level=logging.DEBUG,
    format="[%(levelname)s] %(message)s"
)

with Progress() as progress:
    task_1 = progress.add_task("[red]○ Initializing Flight Control Computers...", total=1000)
    task_2 = progress.add_task("[red]○ Establishing Communication Links...", total=1000)
    task_3 = progress.add_task("[red]○ Activating Flight Control Panel...", total=1000)
    task_4 = progress.add_task("[red]○ Calibrating Navigation Systems...", total=1000)
    task_5 = progress.add_task("[red]○ Charging Guidance Capacitors...", total=1000)
    task_6 = progress.add_task("[red]○ Synchronizing System Clocks...", total=1000)
    task_7 = progress.add_task("[red]○ Validating Flight Software...", total=1000)
    task_8 = progress.add_task("[red]○ Checking Telemetry Channel...", total=1000)
    task_9 = progress.add_task("[red]○ Running Safety Checks...", total=1000)
    task_10 = progress.add_task("[red]○ Arming Flight Systems...", total=1000)
    task_11 = progress.add_task("[red]○ Awaiting Launch Authorization...", total=10000)
    task_12 = progress.add_task("[red]○ Loading Live Telemetry Stream...", total=12000)
    
    while not progress.finished:
        progress.update(task_id=task_1  , advance=0.5)
        progress.update(task_id=task_2  , advance=0.5)
        progress.update(task_id=task_3  , advance=0.4)
        progress.update(task_id=task_4  , advance=0.4)
        progress.update(task_id=task_5  , advance=0.3)
        progress.update(task_id=task_6  , advance=0.3)
        progress.update(task_id=task_7  , advance=0.2)
        progress.update(task_id=task_8  , advance=0.2)
        progress.update(task_id=task_9  , advance=0.2)
        progress.update(task_id=task_10 , advance=0.2)
        progress.update(task_id=task_11 , advance=0.8)
        progress.update(task_id=task_12 , advance=0.9)
        
        for task in progress.tasks:
            desc = task.description
            if task.finished and not desc.startswith("[green]"):
                progress.update(task.id, description=desc.replace("[red]○", "[green]✓"))
    
        time.sleep(0.1)