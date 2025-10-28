# pylint: skip-file

# generators --> produce iterator objects as implements dunder iter and next internally
#                simpler ways to create iterators --> use yield instead of return

# yield pauses func exec and saves state
# mem efficient as vals generated on demand --> lazy eval of functions
# great for large datasets --> no full list created in mem

# generators and iterators are used in data pipelines, streaming and async prog
# use closure mechanism to remember state

def countUP(limit):
    curr = 1
    while curr <= limit:
        yield curr
        curr += 1

for num in countUP(5):
    print(num)

def accumulator():
    total = 0
    while True:
        val = yield total
        if val is None:
            break
        total += val

acc = accumulator()
print(next(acc))
print(acc.send(1))
print(acc.send(2))
print(acc.send(3))
print(acc.send(4))  # .send() --> send a val to paused gen
acc.close()         # .close() --> terminate the generator prematurely


