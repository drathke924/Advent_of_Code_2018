with open('day3.txt') as f:
    data = f.read().splitlines()

rects = []
grid = {}
partone = 0
for s in data:
    s = s[1:].split(' ')
    s.pop(1)
    s[1] = tuple(map(int, s[1][0:-1].split(',')))
    s[2] = tuple(map(int, s[2].split('x')))
    rects.append((s[1][0], s[1][0] + s[2][0] - 1, s[1][1], s[1][1] + s[2][1] - 1))

for xmin, xmax, ymin, ymax in rects:
    for x in range(xmin, xmax + 1):
        for y in range(ymin, ymax + 1):
            try:
                if grid[(x, y)] == 1:
                    grid[(x, y)] += 1
                    partone += 1
            except KeyError:
                grid[(x, y)] = 1

for xmin, xmax, ymin, ymax in rects:
    overlapped = False
    for x in range(xmin, xmax + 1):
        for y in range(ymin, ymax + 1):
            if grid[(x,y)] > 1:
                overlapped = True
                break
    if overlapped == False:
        parttwo = rects.index((xmin, xmax, ymin, ymax)) + 1

print("Part one: " + str(partone))
print("Part two: " + str(parttwo))
