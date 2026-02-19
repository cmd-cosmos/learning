# pylint: skip-file

import asyncio

async def work(n):
    await asyncio.sleep(n)
    return n

async def main():
    tasks = [asyncio.create_task(work(i)) for i in [3, 4, 5]]
    done, pending = await asyncio.wait(tasks)

    for task in done:
        print(f"RESULT: {task.result()}")

if __name__ == "__main__":
    asyncio.run(main())