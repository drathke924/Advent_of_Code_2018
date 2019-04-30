with open('Day1.txt') as f:
    data = list(map(int, f.read().splitlines()))

partone = 0
parttwo = None
found = set()
for i in data:
    partone += i
    if partone in found and parttwo == None:
        parttwo = partone
    else:
        found.add(partone)
if parttwo == None:
    freq = partone
while parttwo == None:
    for i in data:
        freq += i
        if freq in found:
            parttwo = freq
            break
        else:
            found.add(freq)

print("Part one: " + str(partone))
print("Part two: " + str(parttwo))
