with open('day3.txt') as f:
    data = f.read().splitlines()

rects = []
mins = (10000, 10000)
maxes = (0, 0)
for s in data:
    s = s[1:].split(' ')
    s.pop(1)
    s[1] = tuple(map(int, s[1][0:-1].split(',')))
    s[2] = tuple(map(int, s[2].split('x')))
    rects.append((s[1][0], s[1][0] + s[2][0] - 1, s[1][1], s[1][1] + s[2][1] - 1))
    if rects[-1][1] > maxes[0]:
        maxes = (rects[-1][0], maxes[1])
    if rects[-1][3] > maxes[1]:
        maxes = (maxes[0], rects[-1][3])
    if rects[-1][0] < mins[0]:
        mins = (rects[-1][0], mins[1])
    if rects[-1][2] < mins[1]:
        mins = (mins[0], rects[-1][2])

print(rects)
